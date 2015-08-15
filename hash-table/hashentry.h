#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <string>

using namespace std;

class HashEntry {
 private:
  int key;
  string value;
  string lang;
 public:
  HashEntry(int, string, string);
  ~HashEntry();
  int getKey();
  string getValue();
  string getLang();
};

#endif // HASHENTRY_H
