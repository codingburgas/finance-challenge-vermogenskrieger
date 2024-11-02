#include "panel.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    panel financePanel;
    financePanel.show();

    return app.exec();
}
