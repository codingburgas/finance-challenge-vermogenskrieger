#include <QApplication>
#include "login.h"
#include "register.h"
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    RegisterForm registerForm;
    Login loginForm;

    // Connect signals and slots
    QObject::connect(&registerForm, &RegisterForm::registrationSuccessful, [&]() {
        loginForm.show();  // Show login form on successful registration
        registerForm.close(); // Close register form
    });

    QObject::connect(&loginForm, &Login::loginSuccessful, [&]() {
        // Actions to perform after a successful login
        QMessageBox::information(nullptr, "Welcome", "Login successful!"); // Example action
        loginForm.close(); // Close login form
    });

    registerForm.show(); // Show register form first

    return a.exec();
}
