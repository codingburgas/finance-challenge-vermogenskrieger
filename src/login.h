#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class RegisterForm; // Forward declaration of RegisterForm

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void showRegisterForm(); // Declare the showRegisterForm method

signals:
    void loginSuccessful(); // Emit when login is successful

private:
    Ui::Login *ui;
    bool verifyCredentials(const QString &username, const QString &password);
    int failedAttempts;
};

#endif // LOGIN_H
