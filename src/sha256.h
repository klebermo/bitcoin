#ifndef SHA256_H
#define SHA256_H

#define SHA256_BLOCK_SIZE 32

#include <vector>
using namespace std;

#include <array>
using namespace std;

#include <sstream>
using namespace std;

class Sha256
{
public:
    Sha256(vector<uint8_t> data);
    Sha256(array<uint8_t, SHA256_BLOCK_SIZE> data);
    array<uint8_t, SHA256_BLOCK_SIZE> hash();
private:
    vector<uint8_t> source;
};

#endif //SHA256_H
