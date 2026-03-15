#include "Expense_Manage.h"
#include <string>
#include <iomanip>
#include <algorithm>

bool cmp(Transaction a, Transaction b) // Sort theo date -> income -> amount -> name
{
    int a_date = a.getDate().year * 10000 + a.getDate().month * 100 + a.getDate().day;
    int b_date = b.getDate().year * 10000 + b.getDate().month * 100 + b.getDate().day;

    if (a_date != b_date) return a_date < b_date;

    if (a.getType() != b.getType()) return a.getType() > b.getType();

    if (a.getAmount() != b.getAmount()) return a.getAmount() < b.getAmount();

    if (a.getName() != b.getName()) return a.getName() < b.getName();
    
    return false;
}

Transaction Expense_manage::Transaction_input(bool type)
{
    string name;
    double amount;
    Date date;
    string note;

    cout << "Name: ";
    getline(cin, name);

    cout << "Amount: ";
    cin >> amount;

    cout << "Date (DD-MM-YY): ";
    cin >> date.day >> date.month >> date.year;
    cin.ignore();

    cout << "Note: ";
    getline(cin, note);

    return Transaction(name, amount, date, note, type);
}

void Expense_manage::addExpense()
{
    Transactions.push_back(Transaction_input(0));
    remainder -= Transactions.back().getAmount();
    sort(Transactions.begin(),Transactions.end(),cmp); 
}

void Expense_manage::addIncome()
{
    Transactions.push_back(Transaction_input(1));
    remainder += Transactions.back().getAmount();
    sort(Transactions.begin(),Transactions.end(),cmp);
}

void Expense_manage::add_aim()
{
    cout << "Your target: ";
    cin >> aim;
}

void Expense_manage::add_max_expense(){
    cout << "Your max expense: ";
    cin >> max_expense;
}

void Expense_manage::printLine()
{
    cout << string(61, '-') << endl;
}

void Expense_manage::Show_Attribute_Expense()
{
    printLine();
    cout << "| " << left << setw(15) << "Name"
         << "| " << setw(12) << "Amount"
         << "| " << setw(10) << "Date"
         << "| " << setw(15) << "Note"
         << "| " << setw(10) << "Type" << "|\n";
    printLine();
}

void Expense_manage::Show_Day_Expense()
{
    for (int i = 0;i < Transactions.size();i++)
    {
        Transactions[i].Display();
        printLine();
    }
}

void Expense_manage::Notify_Exceed(){
    cout << "WARNING: Ban da su dung qua " << max_expense << " roi!" << endl;
}

void Expense_manage::Notify_Aim_Enough(){
    cout << "CONGRATULATIONS: Ban da tiet kiem du " << aim << " roi!" << endl;
}


