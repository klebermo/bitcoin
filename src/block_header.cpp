#include "block_header.h"

#define c2x(x) (x>='A' && x<='F' ? (x-'A'+10) : x>='a' && x<='f' ? (x-'a'+10) : x-'0')

BlockHeader::BlockHeader() {
  //
}

BlockHeader::~BlockHeader() {
  //
}

int BlockHeader::getVersion() {
  return this->version;
}

void BlockHeader::setVersion(int version) {
  this->version = version;
}

string BlockHeader::getHashPrevBlock() {
  return this->hashPrevBlock;
}

void BlockHeader::setHashPrevBlock(string hashPrevBlock) {
  this->hashPrevBlock = hashPrevBlock;
}

string BlockHeader::getHashMerkleRoot() {
  return this->hashMerkleRoot;
}

void BlockHeader::setHashMerkleRoot(string hashMerkleRoot) {
  this->hashMerkleRoot = hashMerkleRoot;
}

int BlockHeader::getTime() {
  return this->time;
}

void BlockHeader::setTime(int time) {
  this->time = time;
}

int BlockHeader::getBits() {
  return this->bits;
}

void BlockHeader::setBits(int bits) {
  this->bits = bits;
}

int BlockHeader::getNonce() {
  return this->nonce;
}

void BlockHeader::setNonce(int nonce) {
  this->nonce = nonce;
}

vector<uint8_t> BlockHeader::bytes() {
    vector<uint8_t> bytes;

    for (int i=24; i>=0; i-=8)
      bytes.push_back( version>>i );

    for (size_t i=0; i<hashPrevBlock.size(); i+=2)
        bytes.push_back( c2x(hashPrevBlock[i]) << 4 | c2x(hashPrevBlock[i+1]) );

    for (size_t i=0; i<hashMerkleRoot.size(); i+=2)
        bytes.push_back( c2x(hashMerkleRoot[i])<<4 | c2x(hashMerkleRoot[i+1]) );

    for (int i=24; i>=0; i-=8)
      bytes.push_back( time>>i );

    for (int i=24; i>=0; i-=8)
      bytes.push_back( bits>>i );

    for (int i=24; i>=0; i-=8)
      bytes.push_back( nonce>>i );

    return bytes;
}
