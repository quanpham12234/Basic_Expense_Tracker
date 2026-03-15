#include "../Head_File/File_Manage.h"
#include <fstream>
#include <string>
#include <sstream>

void File_Manage::SaveCSV(const vector<Transaction> &data)
{
    ofstream fout("transaction.csv");

    if (!fout)
    {
        cout << "Can't open file \n";
        return;
    }
    fout << "Name;Amount;Day;Month;Year;Note;Type\n";

    for (const auto &t : data)
    {
        fout << t.getName() << ";";
        fout << t.getAmount() << ";";
        fout << t.getDate().day << ";";
        fout << t.getDate().month << ";";
        fout << t.getDate().year << ";";
        fout << t.getNote() << ";";

        if (t.getType() == 1)
            fout << "INCOME";
        else
            fout << "OUTCOME";

        fout << "\n";
    }

    fout.close();

    cout << "Finish save file!" << endl;
}

void File_Manage::LoadCSV(vector<Transaction> &data)
{
    data.clear();
    ifstream fin("transaction.csv");

    if (!fin)
    {
        cout << "Can't open file\n";
        return;
    }
    string line;
    getline(fin, line);

    while (getline(fin, line))
    {
        if (line.empty()) continue;
        stringstream ss(line);

        string name, amountStr, dayStr, monthStr, yearStr, note, typeStr;
        getline(ss, name, ';'); // stop at ';'
        getline(ss, amountStr, ';');
        getline(ss, dayStr, ';');
        getline(ss, monthStr, ';');
        getline(ss, yearStr, ';');
        getline(ss, note, ';');
        getline(ss, typeStr, ';');

        double amount = stod(amountStr);

        Date d;
        d.day = stoi(dayStr);
        d.month = stoi(monthStr);
        d.year = stoi(yearStr);

        bool type = (typeStr == "INCOME") ? 1 : 0;

        Transaction t(name, amount, d, note, type);

        data.push_back(t);
    }
}