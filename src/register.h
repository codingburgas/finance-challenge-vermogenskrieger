#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QWidget {
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

signals:
    void registrationSuccessful(); // Signal for successful registration
    void loginRequested(); // New signal for login request

private slots:
    void on_registerButton_clicked();

private:
    bool validateInputs(const QString &username, const QString &password, const QString &confirmPassword);
    bool usernameExists(const QString &username);
    Ui::RegisterForm *ui;
};

#endif // REGISTER_H
