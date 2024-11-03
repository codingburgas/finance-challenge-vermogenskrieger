#pragma once

#include <QWidget> // Base class for all UI objects in Qt
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>

namespace Ui {
class Login; // Forward declaration of the UI class associated with this login widget
}

// Login class handles user authentication
class Login : public QWidget {
    Q_OBJECT // Enable Qt's signal and slot mechanism

public:
    explicit Login(QWidget *parent = nullptr); // Constructor, initializes the login widget
    ~Login(); // Destructor, cleans up resources

private slots:
    void loginButtonClicked(); // Slot for handling login button clicks
    void forgotButtonClicked(); // Slot for handling forgot password button clicks

signals:
    void loginSuccessful(); // Signal emitted when login is successful
    void showRegisterRequested(); // Signal emitted to request displaying the registration page

private:
    Ui::Login *ui; // Pointer to the UI elements defined in the associated .ui file
    bool verifyCredentials(const QString &username, const QString &password); // Method to verify user credentials
    int failedAttempts; // Counter for tracking the number of failed login attempts
};
