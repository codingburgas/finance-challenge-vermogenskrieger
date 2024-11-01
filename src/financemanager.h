#pragma once
#include <string>
#include <vector>
#include <map>

struct Transaction {
    std::string date;
    std::string category;
    double amount;
};

class FinanceManager {
private:
    std::vector<Transaction> incomes;
    std::vector<Transaction> expenses;
    std::map<std::string, double> budget;

public:
    // Income Management
    void addIncome(const std::string& date, const std::string& category, double amount);
    double getTotalIncome() const;
    double getMonthlyIncome(const std::string& month) const;

    // Expense Management
    void addExpense(const std::string& date, const std::string& category, double amount);
    double getTotalExpense() const;
    double getMonthlyExpense(const std::string& month) const;

    // Budget Planning
    void setBudget(const std::string& category, double amount);
    double getUtilization(const std::string& category) const;
    double getRemainingBudget(const std::string& category) const;

    // Report Generation
    double getNetIncome() const;
    std::map<std::string, double> getCategorySummary(const std::string& category) const;

    // Expense Analysis
    std::map<std::string, double> getCategoryPercentage() const;
    double getAverageMonthlyExpense(const std::string& category, int monthsTracked) const;

};
