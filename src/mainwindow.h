#pragma once

#include <QMainWindow> // Include the QMainWindow class, which provides the main application window
#include <QStackedWidget> // Include QStackedWidget for managing multiple pages

#include "login.h" // Include the login page class
#include "register.h" // Include the registration page class
#include "panel.h" // Include the finance panel class

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // Forward declaration for the UI namespace
QT_END_NAMESPACE

// Main application window class
class MainWindow : public QMainWindow {
    Q_OBJECT // Macro to enable Qt's signal and slot mechanism

public:
    // Constructor to initialize the main window
    MainWindow(QWidget *parent = nullptr);
    // Destructor to clean up resources
    ~MainWindow();

private slots:
    // Slot to switch to the login page
    void showLogin();
    // Slot to switch to the registration page
    void showRegister();
    // Slot to show the finance management panel after login
    void showPanel();
    // Slot to handle successful login events
    void onLoginSuccessful();

private:
    Ui::MainWindow *ui; // Pointer to the UI elements defined in the associated .ui file
    Login *loginPage; // Pointer to the login page object
    RegisterForm *registerPage; // Pointer to the registration form object
    FinancePanel *panel; // Pointer to the finance management panel
};
