#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <vector>
using namespace std;

#include <string>
using namespace std;

#include <cstring>
using namespace std;

class Transaction
{
private:
  string data;
  string txid;
  string hash;
  vector<string> depends;
  float fee;
  int sigops;
  int weight;
public:
    Transaction();
    ~Transaction();
    vector<uint8_t> bytes();

    string getData();
    void setData(string data);

    string getTxid();
    void setTxid(string txid);

    string getHash();
    void setHash(string hash);

    vector<string> getDepends();
    void setDepends(vector<string> depends);

    float getFee();
    void setFee(float fee);

    int getSigops();
    void setSigops(int sigops);

    int getWeight();
    void setWeight(int weight);
};

#endif //TRANSACTION_H
