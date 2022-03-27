#ifndef MERKEL_NODE_H
#define MERKEL_NODE_H

#include "sha256.h"
#include "transaction.h"

class MerkleNode
{
public:
    MerkleNode();
    MerkleNode(Transaction * tx);
    ~MerkleNode();

    array<uint8_t, SHA256_BLOCK_SIZE> getHash();

    Transaction * getTransaction();

    MerkleNode * getLeft();
    void setLeft(MerkleNode * left);

    MerkleNode * getRight();
    void setRight(MerkleNode * right);
private:
  Transaction * tx;
  string hash;
  MerkleNode * left;
  MerkleNode * right;
};

#endif //MERKEL_NODE_H
