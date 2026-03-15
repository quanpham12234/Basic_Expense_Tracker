#include "../Head_File/Transaction.h"
#include <iomanip>
#include <string>

Transaction::Transaction(string n, double a, Date d, string no, bool t){
    name = n;
    amount = a;
    date = d;
    note = no;
    type = t;
}

string Date::toString()
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

void Transaction::Display(){
    cout << "| "
     << left << setw(15) << name
     << "| " << setw(12) << fixed << setprecision(0) << amount
     << "| " << setw(15) << date.toString()
     << "| " << setw(15) << note;
     if (type == 1) cout << "| " << setw(10) << "INCOME";
     else cout << "| " << setw(10) << "OUTCOME";
     cout << "|\n";
}

double Transaction::getAmount() const{
    return amount;
}

Date Transaction::getDate() const{
    return date;
}

bool Transaction::getType() const {
    return type;
}

string Transaction::getName() const
{
    return name;
}

string Transaction::getNote() const {
    return note;
}