#ifndef BLOCK_H
#define BLOCK_H

#include "block_header.h"
#include "var_int.h"
#include "transaction.h"
#include "merkle_tree.h"

#include <vector>
using namespace std;

class Block
{
private:
  int magic_number;
  int block_size;
  BlockHeader block_header;
  VarInt transaction_counter;
  vector<Transaction> transactions;
public:
    Block();
    ~Block();
    vector<uint8_t> bytes();

    int getMagicNumber();
    void setMagicNumber(int magic_number);

    int getBlockSize();
    void setBlockSize(int block_size);

    BlockHeader getBlockHeader();
    void setBlockHeader(BlockHeader block_header);

    VarInt getTransactionCounter();
    void setTransactionCounter(VarInt transaction_counter);

    vector<Transaction> getTransaction();
    void setTransaction(vector<Transaction> transactions);
};

#endif //BLOCK_H
