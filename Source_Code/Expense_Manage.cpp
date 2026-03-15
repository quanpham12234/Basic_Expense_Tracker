#include "../Head_File/Expense_Manage.h"
#include <string>
#include <iomanip>
#include <algorithm>

bool cmp(Transaction a,Transaction b) // Sort theo date -> income -> amount -> name
{
    int a_date = a.getDate().year * 10000 + a.getDate().month * 100 + a.getDate().day;
    int b_date = b.getDate().year * 10000 + b.getDate().month * 100 + b.getDate().day;

    if (a_date != b_date) return a_date < b_date;

    if (a.getType() != b.getType()) return a.getType() > b.getType();

    if (a.getAmount() != b.getAmount()) return a.getAmount() < b.getAmount();

    if (a.getName() != b.getName()) return a.getName() < b.getName();
    
    return false;
}

double Exchange_Date(const Date &a){
    double date = a.year * 10000 + a.month * 100 + a.day;
    return date;
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
    sort(Transactions.begin(),Transactions.end(),cmp); 
}

void Expense_manage::addIncome()
{
    Transactions.push_back(Transaction_input(1));
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
    cout << "Limit From (DD-MM-YY): ";
    cin >> Start_Limit.day >> Start_Limit.month >> Start_Limit.year;

    cout << "Limit End (DD-MM-YY): ";
    cin >> End_Limit.day >> End_Limit.month >> End_Limit.year;
}

double Expense_manage::get_Total(){
    double sum = 0;
    for (auto it : Transactions)
        sum += (it.getType() == 1)? it.getAmount() : -it.getAmount();

    return sum;
}

double Expense_manage::get_aim(){
    return aim;
}

double Expense_manage::get_max_expense(){
    return max_expense;
}

double Expense_manage::get_Total_expense(){
    double sum = 0;

    for (auto it : Transactions)
    {
        if (!it.getType() && (Exchange_Date(it.getDate()) <= Exchange_Date(End_Limit) && Exchange_Date(Start_Limit) <= Exchange_Date(it.getDate())))
        sum += it.getAmount();
    }
    return sum;
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

vector<Transaction>& Expense_manage::getTransactions()
{
    return Transactions;
}

