#include "json_factory.h"
#include "transaction_factory.h"

#include <iostream>
using namespace std;

int main() {
  JsonFactory jf;
  BlockTemplate bt = jf.getBlockTemplate();
  TransactionFactory tf(bt.getTransactions());
}
