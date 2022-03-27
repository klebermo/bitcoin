#ifndef BLOCK_HEADER_H
#define BLOCK_HEADER_H

#include <string>
using namespace std;

#include <vector>
using namespace std;

#include <sstream>
using namespace std;

#include <iostream>
using namespace std;

#include <iomanip>
using namespace std;

class BlockHeader
{
private:
  int version;
  string hashPrevBlock;
  string hashMerkleRoot;
  int time;
  int bits;
  int nonce;
public:
    BlockHeader();
    ~BlockHeader();
    vector<uint8_t> bytes();

    int getVersion();
    void setVersion(int version);

    string getHashPrevBlock();
    void setHashPrevBlock(string hashPrevBlock);

    string getHashMerkleRoot();
    void setHashMerkleRoot(string hashMerkleRoot);

    int getTime();
    void setTime(int time);

    int getBits();
    void setBits(int bits);

    int getNonce();
    void setNonce(int nonce);
};

#endif //BLOCK_HEADER_H
