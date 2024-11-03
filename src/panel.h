#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include <QMap> // Include QMap for summary mapping
#include "financemanager.h" // Include your finance manager header
#include <QString>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>


namespace Ui {
class FinancePanel; // Class name updated to match your UI class
}

class FinancePanel : public QWidget {
    Q_OBJECT

public:
    explicit FinancePanel(QWidget *parent = nullptr);
    ~FinancePanel();

private slots:
    QString getFile();
    void on_addIncomeButton_clicked();
    void on_addExpenseButton_clicked();
    void on_setBudgetButton_clicked();
    void on_generateReportButton_clicked();

private:
    void updateTotalIncome();
    void updateTotalExpense();
    void updateUtilizationAndRemaining();
    void updateNetIncome();
    void updateCategorySummary();

    Ui::FinancePanel *ui; // Updated to match your UI class
    FinanceManager financeManager; // Assuming you have a finance manager class

    QChartView* createExpensePieChart() const;
    QChartView* createExpenseBarChart() const;

    // UI to hold the charts
    QChartView *pieChartView;
    QChartView *barChartView;
};

#endif // PANEL_H
