#include "block.h"

Block::Block() {
  //
}

Block::~Block() {
  //
}

int Block::getMagicNumber() {
  return this->magic_number;
}

void Block::setMagicNumber(int magic_number) {
  this->magic_number = magic_number;
}

int Block::getBlockSize() {
  return this->block_size;
}

void Block::setBlockSize(int block_size) {
  this->block_size = block_size;
}

BlockHeader Block::getBlockHeader() {
  return this->block_header;
}

void Block::setBlockHeader(BlockHeader block_header) {
  this->block_header = block_header;
}

VarInt Block::getTransactionCounter() {
  return this->transaction_counter;
}

void Block::setTransactionCounter(VarInt transaction_counter) {
  this->transaction_counter = transaction_counter;
}

vector<Transaction> Block::getTransaction() {
  return this->transactions;
}

void Block::setTransaction(vector<Transaction> transactions) {
  this->transactions = transactions;
}

vector<uint8_t> Block::bytes() {
  vector<uint8_t> result;

  for (int i=24; i>=0; i-=8)
    result.push_back( magic_number>>i );

  for (int i=24; i>=0; i-=8)
    result.push_back( block_size>>i );

  result.insert(result.end(), block_header.bytes().begin(), block_header.bytes().end());

  result.insert(result.end(), transaction_counter.getData().begin(), transaction_counter.getData().end());

  for(int i=0; i<transactions.size(); i++)
    result.insert(result.end(), transactions[i].bytes().begin(), transactions[i].bytes().end());

  return result;
}
