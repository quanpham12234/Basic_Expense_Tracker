#include "Transaction.h"
#include <vector>

class File_Manage{
    public:
    void SaveCSV(const vector<Transaction> &data);
    void LoadCSV(vector<Transaction> &data);
};