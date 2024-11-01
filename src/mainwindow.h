#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();  // Слот за бутона за логин

private:
    Ui::MainWindow *ui;

    // Функция за проверка на потребителско име и парола
    bool verifyCredentials(const QString &username, const QString &password);
};

#endif // MAINWINDOW_H
