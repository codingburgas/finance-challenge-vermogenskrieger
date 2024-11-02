#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <string>
#include <vector>
#include <map>

class FinanceManager {
public:
    void addIncome(const std::string& date, const std::string& category, double amount);
    double getTotalIncome() const;
    double getMonthlyIncome(const std::string& month) const;

    void addExpense(const std::string& date, const std::string& category, double amount);
    double getTotalExpense() const;
    double getMonthlyExpense(const std::string& month) const;

    void setBudget(const std::string& category, double amount);
    double getUtilization(const std::string& category) const;
    double getRemainingBudget(const std::string& category) const;

    double getNetIncome() const;
    std::map<std::string, double> getCategorySummary(const std::string& category) const;
    std::map<std::string, double> getCategoryPercentage() const;
    double getAverageMonthlyExpense(const std::string& category, int monthsTracked) const;

private:
    struct Transaction {
        std::string date;
        std::string category;
        double amount;
    };

    std::vector<Transaction> incomes;
    std::vector<Transaction> expenses;
    std::map<std::string, double> budget;
};

#endif // FINANCEMANAGER_H
