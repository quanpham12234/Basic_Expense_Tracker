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

void Transaction::Display(){
    cout << "| "
     << left << setw(15) << name
     << "| " << setw(12) << amount
     << "| " << setw(10) << date.day << "/" << date.month << "/" << date.year
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