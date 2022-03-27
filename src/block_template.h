#ifndef BLOCK_TEMPLATE_H
#define BLOCK_TEMPLATE_H

#include "block.h"

#include <vector>
using namespace std;

#include <string>
using namespace std;

class BlockTemplate
{
private:
  int version;
  vector<string> capabilities;
  vector<string> rules;
  vector<int> vbavailable;
  int vbrequired;
  string previousblockhash;
  vector<Transaction> transactions;
  vector<string> coinbaseaux;
  int coinbasevalue;
  string longpollid;
  string target;
  int mintime;
  vector<string> v_mutable;
  string noncerange;
  int sigoplimit;
  int sizelimit;
  int weightlimit;
  int curtime;
  string bits;
  int height;
  string default_witness_commitment;
public:
    BlockTemplate();
    ~BlockTemplate();
    BlockTemplate& operator=(const BlockTemplate& other);

    int getVersion();
    void setVersion(int version);

    vector<string> getCapabilities();
    void setCapabilities(vector<string> capabilities);

    vector<string> getRules();
    void setRules(vector<string> rules);

    vector<int> getVbavailable();
    void setVbavailable(vector<int> vbavailable);

    int getVbrequired();
    void setVbrequired(int vbrequired);

    string getPreviousBlockHash();
    void setPreviousBlockHash(string previousblockhash);

    vector<Transaction> getTransactions();
    void setTransactions(vector<Transaction> transactions);

    vector<string> getCoinbaseaux();
    void setCoinbaseaux(vector<string> coinbaseaux);

    int getCoinbasevalue();
    void setCoinbasevalue(int coinbasevalue);

    string getLongpollid();
    void setLongpollid(string longpollid);

    string getTarget();
    void setTarget(string target);

    int getMintime();
    void setMintime(int mintime);

    vector<string> getMutable();
    void setMutable(vector<string> v_mutable);

    string getNoncerange();
    void setNoncerange(string noncerange);

    int getSigoplimit();
    void setSigoplimit(int sigoplimit);

    int getSizelimit();
    void setSizelimit(int sizelimit);

    int getWeightlimit();
    void setWeightlimit(int weightlimit);

    int getCurtime();
    void setCurtime(int curtime);

    string getBits();
    void setBits(string bits);

    int getHeight();
    void setHeight(int height);

    string getDefaultWitnessCommitment();
    void setDefaultWitnessCommitment(string default_witness_commitment);
};

#endif //BLOCK_TEMPLATE_H
