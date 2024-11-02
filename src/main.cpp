#include <QApplication>
#include "panel.h"  // Ensure you include the correct header file for your class

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create an instance of FinancePanel
    FinancePanel financePanel;  // Corrected to match the class name
    financePanel.show();         // Show the main window

    return app.exec();           // Start the application event loop
}
