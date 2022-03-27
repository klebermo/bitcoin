#include "merkle_tree.h"

bool flagged;

MerkleTree::MerkleTree(list<Transaction> transactions) {
  for(int i=0; i<transactions.size(); i+=2) {
    flagged = true;
    auto item = std::next(transactions.begin(), i);
    insert_node(*item, root);
  }

  for(int i=1; i<transactions.size(); i+=2) {
    flagged = false;
    auto item = std::next(transactions.begin(), i);
    insert_node(*item, root);
  }
}

MerkleTree::~MerkleTree() {
  //
}

void MerkleTree::insert_node(Transaction transaction, MerkleNode * node) {
  if(flagged) {
    if(node->getLeft() == NULL) {
      node->setLeft(new MerkleNode(&transaction));
    } else {
      insert_node(transaction, node->getLeft());
    }
  } else {
    if(node->getRight() == NULL) {
      node->setRight(new MerkleNode(&transaction));
    } else {
      insert_node(transaction, node->getRight());
    }
  }
}

array<uint8_t, SHA256_BLOCK_SIZE> MerkleTree::hash() {
  return root->getHash();
}
