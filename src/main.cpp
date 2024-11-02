#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the login form
    Login loginForm;

    // Connect the login successful signal to quit the application (optional)
    QObject::connect(&loginForm, &Login::loginSuccessful, &app, &QApplication::quit);

    // Show the login form
    loginForm.show();

    return app.exec(); // Start the event loop
}
