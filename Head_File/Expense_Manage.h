#ifndef EXPENSE_MANAGE_H
#define EXPENSE_MANAGE_H

#include "Transaction.h"
#include <vector>

using namespace std;

class Expense_manage
{
private:
    vector<Transaction> Transactions;
    static double remainder;
    double aim;
    double max_expense;

public:
    Transaction Transaction_input(bool type);
    void addIncome();
    void addExpense();
    void add_aim();
    void add_max_expense();

    void printLine();

    void Show_Attribute_Expense();

    void Show_Day_Expense();

    void Notify_Exceed();

    void Notify_Aim_Enough(); // If Sum_Amount = aim -> notify

    // void weekly_report();
    // void monthly_report();
    
};

#endif