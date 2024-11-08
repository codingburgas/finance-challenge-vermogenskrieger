#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void on_forgotButton_clicked(); // Slot for forgot password button

signals:
    void loginSuccessful();
    void showRegisterRequested(); // Signal to request showing the register page
    void onLoginSuccessful();

private:
    Ui::Login *ui;
    bool verifyCredentials(const QString &username, const QString &password);
    int failedAttempts;
};

#endif // LOGIN_H
