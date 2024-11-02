#include "register.h"
#include "ui_register.h"

RegisterForm::RegisterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
    ui->statusLabel->clear();  // Clear the status label at startup
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
        ui->statusLabel->setText("Registration successful!");
        ui->statusLabel->setStyleSheet("QLabel { color : green; font-weight: bold; }");

        // Clear the input fields after successful registration
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();
        ui->confirmPasswordLineEdit->clear();

        // Emit signal to indicate successful registration
        emit registrationSuccessful(); // Emit the signal
    } else {
        ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");
    }
}
