#ifndef HASHDICTIONARY_H
#define HASHDICTIONARY_H

#include "hashentry.h"
#include <cstring>

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
  int DICT_SIZE;
 protected:
  int hashWord(string);
};

#endif // HASHDICTIONARY_H
