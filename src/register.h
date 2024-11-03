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
    void loginRequested();          // Signal emitted when "Already have an account" is clicked
    void registrationSuccessful();  // Signal emitted when registration is successful

private slots:
    void on_registerButton_clicked();
    void createUserFile(const QString &username);

private:
    Ui::RegisterForm *ui;
    bool validateInputs(const QString &username, const QString &password, const QString &confirmPassword);
    bool usernameExists(const QString &username);
};

#endif // REGISTER_H
