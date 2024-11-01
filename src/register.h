#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RegisterForm; }
QT_END_NAMESPACE

class RegisterForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

private slots:
    void on_registerButton_clicked();

private:
    Ui::RegisterForm *ui;
    bool validateInputs(const QString &username, const QString &password, const QString &confirmPassword);
};

#endif // REGISTERFORM_H
