#ifndef VAR_INT_H
#define VAR_INT_H

#include <vector>
using namespace std;

#include <cstdint>
using namespace std;

typedef unsigned char uint8_t;

class VarInt
{
public:
    VarInt();
    ~VarInt();
    vector<uint8_t> getData();
    void setData(long size);
private:
    vector<uint8_t> data;
};

#endif //VAR_INT_H
