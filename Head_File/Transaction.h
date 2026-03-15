#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

struct Date{
    int day, month, year;
    string toString();
};

class Transaction{
    private:
    string name;
    double amount;  
    Date date;
    string note;
    bool type; // in = 1 or out = 0

    public:
    Transaction(string n, double a, Date d, string no, bool t);

    void Display();
    double getAmount() const;
    Date getDate() const;
    bool getType() const ;
    string getName() const;
    string getNote() const;

    bool operator==(const Transaction& other)
    {
        return (other.getDate().day == this->date.day && other.getDate().month == this->date.month && other.getDate().year == this->date.year);
    }
};

#endif