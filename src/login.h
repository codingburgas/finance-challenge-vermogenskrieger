#ifndef LOGIN_H  // Check if LOGIN_H is not defined
#define LOGIN_H  // Define LOGIN_H

#include <QWidget>  // Include necessary Qt header files

namespace Ui {
class Login;  // Forward declaration of the UI class
}

class Login : public QWidget {
    Q_OBJECT  // Macro for Qt's meta-object features

public:
    explicit Login(QWidget *parent = nullptr);  // Constructor
    ~Login();  // Destructor

private:
    Ui::Login *ui;  // Pointer to the UI class

private slots:
    void on_loginButton_clicked();  // Slot for button click
    bool verifyCredentials(const QString &username, const QString &password);  // Function to verify credentials
};

#endif // LOGIN_H  // End of the header guard
