#include "transaction.h"

#define c2x(x) (x>='A' && x<='F' ? (x-'A'+10) : x>='a' && x<='f' ? (x-'a'+10) : x-'0')

Transaction::Transaction() {
  //
}

Transaction::~Transaction() {
  //
}

string Transaction::getData() {
  return this->data;
}

void Transaction::setData(string data) {
  this->data = data;
}

string Transaction::getTxid() {
  return this->txid;
}

void Transaction::setTxid(string txid) {
  this->txid = txid;
}

string Transaction::getHash() {
  return this->hash;
}

void Transaction::setHash(string hash) {
  this->hash = hash;
}

vector<string> Transaction::getDepends() {
  return this->depends;
}

void Transaction::setDepends(vector<string> depends) {
  this->depends = depends;
}

float Transaction::getFee() {
  return this->fee;
}

void Transaction::setFee(float fee) {
  this->fee = fee;
}

int Transaction::getSigops() {
  return this->sigops;
}

void Transaction::setSigops(int sigops) {
  this->sigops = sigops;
}

int Transaction::getWeight() {
  return this->weight;
}

void Transaction::setWeight(int weight) {
  this->weight = weight;
}

vector<uint8_t> Transaction::bytes() {
  vector<uint8_t> result;

  for (size_t i=0; i<data.size(); i+=2)
      result.push_back( c2x(data[i]) << 4 | c2x(data[i+1]) );

  for (size_t i=0; i<txid.size(); i+=2)
      result.push_back( c2x(txid[i]) << 4 | c2x(txid[i+1]) );

  for (size_t i=0; i<hash.size(); i+=2)
      result.push_back( c2x(hash[i]) << 4 | c2x(hash[i+1]) );

  for(int i=0; i<depends.size(); i++)
    for (size_t i=0; i<depends[i].size(); i++)
      for(int j=0; j<depends[i].size(); j+=2)
        result.push_back( c2x(depends[i][j]) << 4 | c2x(depends[i][j+1]) );

  vector<uint8_t> temp;
  temp.resize(sizeof(float));
  memcpy(temp.data(), &fee, sizeof(fee));
  result.insert(result.end(), temp.begin(), temp.end());

  for (int i=24; i>=0; i-=8)
    result.push_back( sigops>>i );

  for (int i=24; i>=0; i-=8)
    result.push_back( weight>>i );

  return result;
}
