#include "register.h"
#include "ui_register.h"
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>

RegisterForm::RegisterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
    ui->statusLabel->clear();  // Make sure to initialize the status label

    // Connect the already have an account button to emit the loginRequested signal
    connect(ui->alreadyHaveAccountButton, &QPushButton::clicked, this, &RegisterForm::loginRequested);
}

RegisterForm::~RegisterForm() {
    delete ui;
}

// Validate user inputs
bool RegisterForm::validateInputs(const QString &username, const QString &password, const QString &confirmPassword) {
    if (username.isEmpty()) {
        ui->statusLabel->setText("Username is required.");
        return false;
    }
    if (password.isEmpty()) {
        ui->statusLabel->setText("Password is required.");
        return false;
    }
    if (password != confirmPassword) {
        ui->statusLabel->setText("Passwords do not match.");
        return false;
    }
    return true;
}

// Check if username already exists in the file
bool RegisterForm::usernameExists(const QString &username) {
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;  // Can't check if file is accessible
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList credentials = line.split(" ");
        if (credentials.size() == 2 && credentials[0] == username) {
            file.close();
            return true;  // Username already exists
        }
    }
    file.close();
    return false;  // Username does not exist
}

// Handle the register button click
void RegisterForm::on_registerButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (validateInputs(username, password, confirmPassword)) {
        if (usernameExists(username)) {
            ui->statusLabel->setText("Username already exists.");
            ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");
            return;  // Username conflict
        }

        // Hash the password for secure storage
        QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

        // Save the username and hashed password to a file
        QFile file("users.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << username << " " << hashedPassword << "\n"; // Store username and hashed password
            file.close();
        } else {
            QMessageBox::critical(this, "Error", "Unable to open user data file.");
            return; // Exit if file can't be opened
        }

        ui->statusLabel->setText("Registration successful!");
        ui->statusLabel->setStyleSheet("QLabel { color : green; font-weight: bold; }");

        // Clear input fields
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();
        ui->confirmPasswordLineEdit->clear();

        emit registrationSuccessful(); // Emit the signal
    } else {
        ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");
    }
}
