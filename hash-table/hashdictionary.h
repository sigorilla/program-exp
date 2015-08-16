#ifndef HASHDICTIONARY_H
#define HASHDICTIONARY_H

#include "hashentry.h"
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

class HashDictionary {
 private:
  HashEntry **dictionary;
 public:
  HashDictionary();
  HashDictionary(int);
  ~HashDictionary();
  string get(string);
  void insert(string, string);
  string translate(string);
  int DICT_SIZE;
 protected:
  int hashWord(string);
  vector<string> split(const string &, char);
};

#endif // HASHDICTIONARY_H
