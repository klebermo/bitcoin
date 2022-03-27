#include "transaction_factory.h"

bool compare(Transaction tx1, Transaction tx2) {
  return tx1.getFee() > tx2.getFee();
}

TransactionFactory::TransactionFactory() {
  //
}

TransactionFactory::TransactionFactory(vector<Transaction> transactions) {
  for(int i=0; i<transactions.size(); i++)
    transactions_list.insert(transactions_list.end(), transactions[i]);
  transactions_list.sort(compare);
}

TransactionFactory::~TransactionFactory() {
  //
}

list<Transaction> TransactionFactory::all() {
  return transactions_list;
}

int TransactionFactory::total_weight() {
  int result = 0;
  for (Transaction i : transactions_list)
      result += i.getWeight();
  return result;
}

list<Transaction> TransactionFactory::top() {
  list<Transaction> result;
  int weight = 0;
  for_each(transactions_list.begin(), transactions_list.end(), [&](Transaction n) {
    if(weight < MAX_BLOCK_SIZE)
      result.insert(result.end(), n);
    weight += n.getWeight();
  });
  return result;
}

int TransactionFactory::top_weight() {
  int result = 0;
  for (Transaction i : top())
      result += i.getWeight();
  return result;
}

list<Transaction> TransactionFactory::bottom() {
  list<Transaction> result;
  int weight = 0;
  for_each(transactions_list.rbegin(), transactions_list.rend(), [&](Transaction n) {
    if(weight < MAX_BLOCK_SIZE)
      result.insert(result.end(), n);
    weight += n.getWeight();
  });
  return result;
}

int TransactionFactory::bottom_weight() {
  int result = 0;
  for (Transaction i : bottom())
      result += i.getWeight();
  return result;
}

array<uint8_t, SHA256_BLOCK_SIZE> TransactionFactory::merkle_root(list<Transaction> transactions) {
  MerkleTree tree(transactions);
  return tree.hash();
}
