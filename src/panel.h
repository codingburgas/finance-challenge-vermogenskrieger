#pragma once

#include "financemanager.h" // Include the finance manager class header

#include <QWidget> // Base class for all UI objects in Qt
#include <QMessageBox> // Include QMessageBox for showing messages to the user
#include <QMap> // Include QMap for mapping summary data
#include <QString> // Include QString for text handling
#include <QtCharts/QChartView> // Include for displaying charts
#include <QtCharts/QPieSeries> // Include for pie chart series
#include <QtCharts/QBarSet> // Include for bar sets in bar charts
#include <QtCharts/QBarSeries> // Include for bar series
#include <QtCharts/QCategoryAxis> // Include for category axis in charts
#include <QtCharts/QValueAxis> // Include for value axis in charts

namespace Ui {
class FinancePanel; // Forward declaration of the UI class associated with this panel
}

// FinancePanel class handles the finance functionalities
class FinancePanel : public QWidget {
    Q_OBJECT // Enable Qt's signal and slot mechanism

public:
    explicit FinancePanel(QWidget *parent = nullptr); // Constructor
    ~FinancePanel(); // Destructor

private slots:
    QString getFile(); // Retrieve the content of a file
    void addIncomeButtonClicked(); // Slot for adding income
    void addExpenseButtonClicked(); // Slot for adding expense
    void setBudgetButtonClicked(); // Slot for setting a budget
    void generateReportButtonClicked(); // Slot for generating a report

private:
    void updateTotalIncome(); // Update displayed total income
    void updateTotalExpense(); // Update displayed total expense
    void updateUtilizationAndRemaining(); // Update budget utilization and remaining amount
    void updateNetIncome(); // Update net income display
    void updateCategorySummary(); // Update summary of categories

    Ui::FinancePanel *ui; // Pointer to the UI elements defined in the associated .ui file
    FinanceManager financeManager; // Instance of the finance manager class for managing finances

    QChartView* createExpensePieChart() const; // Create and return an expense pie chart
    QChartView* createExpenseBarChart() const; // Create and return an expense bar chart

    // Pointers to hold the chart views for expenses
    QChartView *pieChartView; // Pie chart view for displaying expense distribution
    QChartView *barChartView; // Bar chart view for displaying expenses by category
};
