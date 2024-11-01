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
        ui->statusLabel->setText("Потребителското име е задължително."); // "Username is required."
        return false;
    }
    if (password.isEmpty()) {
        ui->statusLabel->setText("Паролата е задължителна."); // "Password is required."
        return false;
    }
    if (password != confirmPassword) {
        ui->statusLabel->setText("Паролите не съвпадат."); // "Passwords do not match."
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
        ui->statusLabel->setText("Регистрацията е успешна!"); // "Registration successful!"
        ui->statusLabel->setStyleSheet("QLabel { color : green; font-weight: bold; }");
        // Add logic here to save the user credentials to a database or file
    } else {
        ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");
    }
}
