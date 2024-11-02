#include "login.h"
#include "ui_login.h"  // Generated from login.ui
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login),
    failedAttempts(0)
{
    ui->setupUi(this);

    // Set placeholder text for input fields
    ui->usernameLineEdit->setPlaceholderText("Enter your username");
    ui->passwordLineEdit->setPlaceholderText("Enter your password");

    // Clear the status label
    if (ui->statusLabel) {
        ui->statusLabel->clear();
    }

    // Connect the login button click to the login function
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::on_loginButton_clicked);
}

Login::~Login()
{
    delete ui;
}

bool Login::verifyCredentials(const QString &username, const QString &password)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open user data file.");
        return false; // Unable to open file
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList credentials = line.split(":");
        if (credentials.size() == 2) {
            QString storedUsername = credentials[0];
            QString storedPasswordHash = credentials[1];

            // Check if username and password match
            if (storedUsername == username && storedPasswordHash == hashedPassword) {
                return true; // Valid credentials
            }
        }
    }

    return false; // No match found
}

void Login::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (verifyCredentials(username, password)) {
        ui->statusLabel->setText("Login successful!");
        ui->statusLabel->setStyleSheet("QLabel { color : green; font-weight: bold; }");

        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();

        // Signal or additional logic for successful login
        accept();  // Close dialog on successful login
    } else {
        ui->statusLabel->setText("Invalid username or password.");
        ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");

        failedAttempts++;
        if (failedAttempts >= 3) {
            QMessageBox::warning(this, "Login Failed", "Please check your credentials.");
            failedAttempts = 0;
        }
    }
}
