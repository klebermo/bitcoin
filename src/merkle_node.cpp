#include "merkle_node.h"

MerkleNode::MerkleNode() {
  //
}

MerkleNode::MerkleNode(Transaction * tx) {
  this->tx = tx;
}

MerkleNode::~MerkleNode() {
  //
}

array<uint8_t, SHA256_BLOCK_SIZE> MerkleNode::getHash() {
  if(left == NULL && right == NULL) {
    Sha256 hash1(tx->bytes());
    Sha256 hash2(hash1.hash());
    return hash2.hash();
  }

  if(left != NULL && right == NULL) {
    vector<uint8_t> input;
    array<uint8_t, SHA256_BLOCK_SIZE> hash = left->getHash();
    input.insert(input.end(), hash.begin(), hash.end());
    input.insert(input.end(), hash.begin(), hash.end());
    Sha256 hash1(input);
    Sha256 hash2(hash1.hash());
    return hash2.hash();
  }

  vector<uint8_t> input;
  array<uint8_t, SHA256_BLOCK_SIZE> hash1 = left->getHash();
  array<uint8_t, SHA256_BLOCK_SIZE> hash2 = right->getHash();
  input.insert(input.end(), hash1.begin(), hash1.end());
  input.insert(input.end(), hash2.begin(), hash2.end());
  Sha256 hashA(input);
  Sha256 hashB(hashA.hash());
  return hashB.hash();
}

Transaction * MerkleNode::getTransaction() {
  return tx;
}

MerkleNode * MerkleNode::getLeft() {
  return left;
}

void MerkleNode::setLeft(MerkleNode * node) {
  this->left = node;
}

MerkleNode * MerkleNode::getRight() {
  return right;
}

void MerkleNode::setRight(MerkleNode * node) {
  this->right = node;
}
