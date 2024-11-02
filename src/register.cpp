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
    ui->statusLabel->clear();
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

// Validate the inputs: ensure password matches confirm password and is not empty
bool RegisterForm::validateInputs(const QString &username, const QString &password, const QString &confirmPassword)
{
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

// Handle the register button click
void RegisterForm::on_registerButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (validateInputs(username, password, confirmPassword)) {
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
