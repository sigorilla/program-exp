#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <string>

using namespace std;

class HashEntry {
 private:
  int key;
  string value;
 public:
  HashEntry(int, string);
  ~HashEntry();
  int getKey();
  string getValue();
};

#endif // HASHENTRY_H
