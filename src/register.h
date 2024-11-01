#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RegisterForm; }
QT_END_NAMESPACE

class RegisterForm : public QWidget {
    Q_OBJECT  // Enable the use of signals and slots

public:
    explicit RegisterForm(QWidget *parent = nullptr);  // Constructor
    ~RegisterForm();  // Destructor

signals:
    void registrationSuccessful(); // Signal emitted when registration is successful

private:
    Ui::RegisterForm *ui;  // Pointer to the UI class

private slots:
    void on_registerButton_clicked();  // Slot for the register button click
    bool validateInputs(const QString &username, const QString &password, const QString &confirmPassword); // Function to validate inputs
};

#endif // REGISTER_H
