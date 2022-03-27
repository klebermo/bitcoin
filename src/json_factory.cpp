#include "json_factory.h"

#include <iostream>
using namespace std;

#include <curl/curl.h>

#include "minijson_reader.hpp"
using namespace minijson;

#include "minijson_writer.hpp"
using namespace minijson;

const char * URL = "http://192.168.0.104:8332/";
const char * USERPWD = "klebermo:123";

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  char *ptr = (char *)realloc(mem->memory, mem->size + realsize + 1);
  if(ptr == NULL) {
    cout << "not enough memory (realloc returned NULL)\n";
    return 0;
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}


JsonFactory::JsonFactory() {
  //
}

JsonFactory::~JsonFactory() {
  //
}

BlockTemplate JsonFactory::getBlockTemplate() {
  BlockTemplate result;

  CURL * curl = curl_easy_init();
  struct curl_slist * headers = NULL;

  struct MemoryStruct chunk;
  chunk.memory = (char *)malloc(1);
  chunk.size = 0;

  if (curl) {
    const char * data = "{\"jsonrpc\": \"1.0\", \"id\":\"jsonrpc\", \"method\": \"getblocktemplate\", \"params\": [{\"rules\": [\"segwit\"]}] }";
    headers = curl_slist_append(headers, "content-type: text/plain;");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(data));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_USERPWD, USERPWD);
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_TRY);

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
    }
    else {
      buffer_context ctx(chunk.memory, chunk.size);
      try {
        parse_object(ctx, [&](const char* k, value v) {
          dispatch (k)
          <<"result">> [&]() {
            try {
              parse_object(ctx, [&](const char* k, value v) {
                dispatch (k)
                <<"version">> [&]() { result.setVersion(v.as_long()); }
                <<"capabilities">> [&]()
                {
                    vector<string> v;
                    parse_array(ctx, [&](value capability)
                    {
                        v.push_back(capability.as_string());
                    });
                    result.setCapabilities(v);
                }
                <<"rules">> [&]()
                {
                    vector<string> v;
                    parse_array(ctx, [&](value rule)
                    {
                        v.push_back(rule.as_string());
                    });
                    result.setRules(v);
                }
                <<"vbavailable">> [&]()
                {
                    parse_object(ctx, [&](const char* k, value vbavailable)
                    {
                        vector<int> v;
                        dispatch (k)
                        <<"rulename">> [&]()
                        {
                          v.push_back(vbavailable.as_long());
                        };
                        result.setVbavailable(v);
                    });
                }
                <<"vbrequired">> [&]() { result.setVbrequired(v.as_long()); }
                <<"previousblockhash">> [&]() { result.setPreviousBlockHash(v.as_string()); }
                <<"transactions">> [&]()
                {
                    vector<Transaction> v;
                    parse_array(ctx, [&](value transaction)
                    {
                        Transaction t;
                        parse_object(ctx, [&](const char* k, value tx)
                        {
                            dispatch(k)
                            <<"data">> [&]() { t.setData(tx.as_string()); }
                            <<"txid">> [&]() { t.setTxid(tx.as_string()); }
                            <<"hash">> [&]() { t.setHash(tx.as_string()); }
                            <<"depends">> [&]() {
                              vector<string> vd;
                                parse_array(ctx, [&](value d)
                                {
                                    vd.push_back(d.as_string());
                                });
                                t.setDepends(vd);
                            }
                            <<"fee">> [&]() { t.setFee(tx.as_double()); }
                            <<"sigops">> [&]() { t.setSigops(tx.as_long()); }
                            <<"weight">> [&]() { t.setWeight(tx.as_long()); };
                        });
                        v.push_back(t);
                    });
                    result.setTransactions(v);
                }
                <<"coinbaseaux">> [&]()
                {
                    parse_object(ctx, [&](const char* k, value coinbaseaux)
                    {
                        vector<string> v;
                        dispatch (k)
                        <<"flags">> [&]()
                        {
                          v.push_back(coinbaseaux.as_string());
                        };
                        result.setCoinbaseaux(v);
                    });
                }
                <<"coinbasevalue">> [&]() { result.setCoinbasevalue(v.as_long()); }
                <<"longpollid">> [&]() { result.setLongpollid(v.as_string()); }
                <<"target">> [&]() { result.setTarget(v.as_string()); }
                <<"mintime">> [&]() { result.setMintime(v.as_long()); }
                <<"mutable">> [&]()
                {
                    vector<string> v;
                    parse_array(ctx, [&](value v_mutable)
                    {
                        v.push_back(v_mutable.as_string());
                    });
                    result.setMutable(v);
                }
                <<"noncerange">> [&]() { result.setNoncerange(v.as_string()); }
                <<"sigoplimit">> [&]() { result.setSigoplimit(v.as_long()); }
                <<"sizelimit">> [&]() { result.setSizelimit(v.as_long()); }
                <<"weightlimit">> [&]() { result.setWeightlimit(v.as_long()); }
                <<"curtime">> [&]() { result.setCurtime(v.as_long()); }
                <<"bits">> [&]() { result.setBits(v.as_string()); }
                <<"height">> [&]() { result.setHeight(v.as_long()); }
                <<"default_witness_commitment">> [&]() { result.setDefaultWitnessCommitment(v.as_string()); };
              });
            } catch (parse_error e) {
              //cout << "[error] " << e.reason() << " at " << e.offset() << endl;
            }
          };
        });
      } catch (parse_error e) {
        //cout << "[error] " << e.reason() << " at " << e.offset() << endl;
      }
    }
  }

  curl_easy_cleanup(curl);
  free(chunk.memory);
  curl_global_cleanup();

  return result;
}

string JsonFactory::getNewAddress(string label, string address_type) {
  string result;

  CURL * curl = curl_easy_init();
  struct curl_slist * headers = NULL;

  struct MemoryStruct chunk;
  chunk.memory = (char *)malloc(1);
  chunk.size = 0;

  if (curl) {
    string temp = "{\"jsonrpc\": \"1.0\", \"id\":\"jsonrpc\", \"method\": \"getnewaddress\", \"params\": [{\"label\": \"" + label + "\"}, {\"address_type\": \"" + address_type + "\"}] }";
    const char * data = temp.c_str();
    headers = curl_slist_append(headers, "content-type: text/plain;");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(data));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_USERPWD, USERPWD);
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_TRY);

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
    } else {
      buffer_context ctx(chunk.memory, chunk.size);
      try {
        //
      } catch (parse_error e) {
        //
      }
    }
  }

  curl_easy_cleanup(curl);
  free(chunk.memory);
  curl_global_cleanup();

  return result;
}

string JsonFactory::createRawTransaction(string address) {
  string result;

  CURL * curl = curl_easy_init();
  struct curl_slist * headers = NULL;

  struct MemoryStruct chunk;
  chunk.memory = (char *)malloc(1);
  chunk.size = 0;

  if (curl) {
    string temp = "{\"jsonrpc\": \"1.0\", \"id\":\"jsonrpc\", \"method\": \"getrawtransaction\", \"params\": [{\"txid\": \" + address + \"}] }";
    const char * data = temp.c_str();
    headers = curl_slist_append(headers, "content-type: text/plain;");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(data));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_USERPWD, USERPWD);
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_TRY);

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
    } else {
      //
    }
  }

  curl_easy_cleanup(curl);
  free(chunk.memory);
  curl_global_cleanup();

  return result;
}

string JsonFactory::submitBlock(Block block, string raw_transaction) {
  string result;

  CURL * curl = curl_easy_init();
  struct curl_slist * headers = NULL;

  struct MemoryStruct chunk;
  chunk.memory = (char *)malloc(1);
  chunk.size = 0;

  if (curl) {
    string temp = "{\"jsonrpc\": \"1.0\", \"id\":\"jsonrpc\", \"method\": \"submitblock\", \"params\": [{\"hexdata\": \" + block.bytes().data() + \"}] }";
    const char * data = temp.c_str();
    headers = curl_slist_append(headers, "content-type: text/plain;");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(data));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_USERPWD, USERPWD);
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_TRY);

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
    } else {
      //
    }
  }

  curl_easy_cleanup(curl);
  free(chunk.memory);
  curl_global_cleanup();

  return result;
}
