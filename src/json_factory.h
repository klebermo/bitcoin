#ifndef JSON_FACTORY_H
#define JSON_FACTORY_H

#include "block_template.h"

class JsonFactory
{
public:
    JsonFactory();
    ~JsonFactory();
    BlockTemplate getBlockTemplate();
    string getNewAddress(string label, string address_type);
    string createRawTransaction(string address);
    string submitBlock(Block block, string raw_transaction);
};

#endif //JSON_FACTORY_H
