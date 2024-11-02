#include <QApplication>
#include "panel.h" // Include the header file for FinancePanel

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FinancePanel financePanel; // Create an instance of FinancePanel
    financePanel.show();       // Show the main FinancePanel window

    return app.exec();
}
