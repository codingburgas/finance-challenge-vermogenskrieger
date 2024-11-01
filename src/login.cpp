#include "login.h"             // Include the header for the Login class
#include "ui_login.h"          // Include the generated UI header from the .ui file
#include <QMessageBox>         // Include QMessageBox for dialog boxes

// Constructor for the Login class
Login::Login(QWidget *parent) :
    QWidget(parent),              // Call the parent constructor
    ui(new Ui::Login)             // Initialize the UI pointer
{
    ui->setupUi(this);            // Setup the UI components from the .ui file
    ui->statusLabel->clear();     // Clear the status label on startup

    // Connect the login button's click signal to the on_loginButton_clicked slot
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::on_loginButton_clicked);
}

// Destructor for the Login class
Login::~Login()
{
    delete ui;                    // Clean up the UI pointer
}

// Function to verify username and password
bool Login::verifyCredentials(const QString &username, const QString &password)
{
    const QString correctUsername = "admin";          // Correct username
    const QString correctPassword = "password123";    // Correct password

    // Check if provided credentials match the correct ones
    return (username == correctUsername && password == correctPassword);
}

// Slot for handling login button click
void Login::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();  // Get the username from input
    QString password = ui->passwordLineEdit->text();  // Get the password from input

    // Verify the credentials
    if (verifyCredentials(username, password)) {
        ui->statusLabel->setText("Login successful!");  // Successful login message
        ui->statusLabel->setStyleSheet("QLabel { color : green; font-weight: bold; }");
        // Logic for transitioning to the main application window can be added here
    } else {
        ui->statusLabel->setText("Invalid username or password.");  // Invalid login message
        ui->statusLabel->setStyleSheet("QLabel { color : red; font-weight: bold; }");
    }
}
