#include "login.h"
#include "ui_login.h"         // Include the generated UI header from the .ui file
#include <QMessageBox>        // Include QMessageBox for dialog boxes

// Constructor for the Login class
Login::Login(QWidget *parent) :
    QWidget(parent),          // Call the parent constructor
    ui(new Ui::Login),        // Initialize the UI pointer
    failedAttempts(0)         // Initialize failed attempts counter
{
    ui->setupUi(this);        // Setup the UI components from the .ui file

    if (ui->statusLabel) {
        ui->statusLabel->clear(); // Clear the status label on startup
    }
    ui->usernameLineEdit->setPlaceholderText("Enter your username");
    // Connect the login button's click signal to the on_loginButton_clicked slot
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::on_loginButton_clicked);
}

// Destructor for the Login class
Login::~Login() {
    delete ui;                // Clean up the UI pointer
}

// Function to verify username and password
bool Login::verifyCredentials(const QString &username, const QString &password) {
    const QString correctUsername = "admin";          // Correct username
    const QString correctPassword = "password123";    // Correct password

    // Check if provided credentials match the correct ones
    return (username == correctUsername && password == correctPassword);
}

// Slot for handling login button click
void Login::on_loginButton_clicked() {
    if (!ui) return; // Safety check to ensure 'ui' is valid

    QString username = ui->usernameLineEdit->text();  // Get the username from input
    QString password = ui->passwordLineEdit->text();  // Get the password from input

    // Verify the credentials
    if (verifyCredentials(username, password)) {
        ui->statusLabel->setText("Login successful!");  // Successful login message
        ui->statusLabel->setStyleSheet("QLabel { color : green; font-weight: bold; }");

        // Clear fields after successful login
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();

        // Emit signal to indicate a successful login
        emit loginSuccessful(); // Emit a signal to transition to the main application window
    } else {
        ui->statusLabel->setText("Invalid username or password.");  // Invalid login message
        ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");

        // Count failed attempts and provide feedback
        failedAttempts++;
        if (failedAttempts >= 3) {
            QMessageBox::warning(this, "Login Failed", "Please check your credentials.");
            failedAttempts = 0;  // Reset attempt counter after showing warning
        }
    }
}
