#ifndef TRANSACTION_FACTORY_H
#define TRANSACTION_FACTORY_H

#include "merkle_tree.h"

const int MAX_BLOCK_SIZE = 1572864;

#include <algorithm>
using namespace std;

class TransactionFactory
{
public:
    TransactionFactory();
    TransactionFactory(vector<Transaction> transactions);
    ~TransactionFactory();

    list<Transaction> all();
    int total_weight();

    list<Transaction> top();
    int top_weight();

    list<Transaction> bottom();
    int bottom_weight();

    array<uint8_t, SHA256_BLOCK_SIZE> merkle_root(list<Transaction> transactions);
private:
    list<Transaction> transactions_list;
};

#endif //TRANSACTION_FACTORY_H
