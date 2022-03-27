#include "block_template.h"

BlockTemplate::BlockTemplate() {
  //
}

BlockTemplate::~BlockTemplate() {
  //
}

BlockTemplate& BlockTemplate::operator=(const BlockTemplate &other) {
  return *this;
}

int BlockTemplate::getVersion() {
  return this->version;
}

void BlockTemplate::setVersion(int version) {
  this->version = version;
}

vector<string> BlockTemplate::getCapabilities() {
  return this->capabilities;
}

void BlockTemplate::setCapabilities(vector<string> capabilities) {
  this->capabilities = capabilities;
}

vector<string> BlockTemplate::getRules() {
  return this->rules;
}

void BlockTemplate::setRules(vector<string> rules) {
  this->rules = rules;
}

vector<int> BlockTemplate::getVbavailable() {
  return this->vbavailable;
}

void BlockTemplate::setVbavailable(vector<int> vbavailable) {
  this->vbavailable = vbavailable;
}

int BlockTemplate::getVbrequired() {
  return this->vbrequired;
}

void BlockTemplate::setVbrequired(int vbrequired) {
  this->vbrequired = vbrequired;
}

string BlockTemplate::getPreviousBlockHash() {
  return this->previousblockhash;
}

void BlockTemplate::setPreviousBlockHash(string previousblockhash) {
  this->previousblockhash = previousblockhash;
}

vector<Transaction> BlockTemplate::getTransactions() {
  return this->transactions;
}

void BlockTemplate::setTransactions(vector<Transaction> transactions) {
  this->transactions = transactions;
}

vector<string> BlockTemplate::getCoinbaseaux() {
  return this->coinbaseaux;
}

void BlockTemplate::setCoinbaseaux(vector<string> coinbaseaux) {
  this->coinbaseaux = coinbaseaux;
}

int BlockTemplate::getCoinbasevalue() {
  return this->coinbasevalue;
}

void BlockTemplate::setCoinbasevalue(int coinbasevalue) {
  this->coinbasevalue = coinbasevalue;
}

string BlockTemplate::getLongpollid() {
  return this->longpollid;
}

void BlockTemplate::setLongpollid(string longpollid) {
  this->longpollid = longpollid;
}

string BlockTemplate::getTarget() {
  return this->target;
}

void BlockTemplate::setTarget(string target) {
  this->target = target;
}

int BlockTemplate::getMintime() {
  return this->mintime;
}

void BlockTemplate::setMintime(int mintime) {
  this->mintime = mintime;
}

vector<string> BlockTemplate::getMutable() {
  return this->v_mutable;
}

void BlockTemplate::setMutable(vector<string> v_mutable) {
  this->v_mutable = v_mutable;
}

string BlockTemplate::getNoncerange() {
  return this->noncerange;
}

void BlockTemplate::setNoncerange(string noncerange) {
  this->noncerange = noncerange;
}

int BlockTemplate::getSigoplimit() {
  return this->sigoplimit;
}

void BlockTemplate::setSigoplimit(int sigoplimit) {
  this->sigoplimit = sigoplimit;
}

int BlockTemplate::getSizelimit() {
  return this->sizelimit;
}

void BlockTemplate::setSizelimit(int sizelimit) {
  this->sizelimit = sizelimit;
}

int BlockTemplate::getWeightlimit() {
  return this->weightlimit;
}

void BlockTemplate::setWeightlimit(int weightlimit) {
  this->weightlimit = weightlimit;
}

int BlockTemplate::getCurtime() {
  return this->curtime;
}

void BlockTemplate::setCurtime(int curtime) {
  this->curtime = curtime;
}

string BlockTemplate::getBits() {
  return this->bits;
}

void BlockTemplate::setBits(string bits) {
  this->bits = bits;
}

int BlockTemplate::getHeight() {
  return this->height;
}

void BlockTemplate::setHeight(int height) {
  this->height = height;
}

string BlockTemplate::getDefaultWitnessCommitment() {
  return this->default_witness_commitment;
}

void BlockTemplate::setDefaultWitnessCommitment(string default_witness_commitment) {
  this->default_witness_commitment = default_witness_commitment;
}
