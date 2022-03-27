#ifndef MERKEL_TREE_H
#define MERKEL_TREE_H

#include "merkle_node.h"

#include <list>
using namespace std;

class MerkleTree
{
public:
    MerkleTree(list<Transaction> transactions);
    ~MerkleTree();
    void insert_node(Transaction transaction, MerkleNode * node);
    array<uint8_t, SHA256_BLOCK_SIZE> hash();
private:
    MerkleNode * root;
};

#endif //MERKEL_TREE_H
