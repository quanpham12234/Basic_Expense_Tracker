#include "Head_File/Expense_Manage.h"
#include "Head_File/File_Manage.h"

using namespace std;

void print_menu()
{
    cout << "\n===== BASIC EXPENSE TRACKER =====\n";
    cout << "1. Add Income\n";
    cout << "2. Add Expense\n";
    cout << "3. Show Transactions\n";
    cout << "4. Set Target\n";
    cout << "5. Set Max Expense\n";
    cout << "6. Save CSV\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

int main()
{
    Expense_manage manage;
    File_Manage file;
    file.LoadCSV(manage.getTransactions());

    int choice;

    do
    {
        print_menu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            manage.addIncome();
            if (manage.get_Total() >= manage.get_aim())
                manage.Notify_Aim_Enough();
        }
        break;
        case 2:
        {
            manage.addExpense();
            if (manage.get_Total_expense() >= manage.get_max_expense())
                manage.Notify_Exceed();
        }

        break;
        case 3:
        {
            cout << "\n";
            manage.Show_Attribute_Expense();
            manage.Show_Day_Expense();
        }
        break;
        case 4:
            manage.add_aim();
            break;
        case 5:
            manage.add_max_expense();
            break;

        case 6: 
        file.SaveCSV(manage.getTransactions());
        break;
        case 0:
        {
            cout << "Close Program!" << endl;
            break;
        }
        default:
            cout << "ERROR! Please choose again: ";
            break;
        }
    } while (choice != 0);
}
