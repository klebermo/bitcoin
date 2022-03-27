#include "var_int.h"

VarInt::VarInt() {
  //
}

VarInt::~VarInt() {
  //
}

vector<uint8_t> VarInt::getData() {
  return data;
}

void VarInt::setData(long size) {
  if(size < 0xFD) {
    uint8_t value = (uint8_t) size;
    data.push_back(value);
  } else if(size <= 0xFFFF) {
    data.push_back(0xFD);
    uint16_t value = (uint16_t) size;
    for (int i = 0; i < sizeof value; i++)
      data[sizeof value - i] = (value >> (i * 8));
  } else if(size <= 0xFFFFFFFF) {
    data.push_back(0xFE);
    uint32_t value = (uint32_t) size;
    for (int i = 0; i < sizeof value; i++)
      data[sizeof value - i] = (value >> (i * 8));
  } else {
    data.push_back(0xFF);
    uint64_t value = (uint64_t) size;
    for (int i = 0; i < sizeof value; i++)
      data[sizeof value - i] = (value >> (i * 8));
  }
}
