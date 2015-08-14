#include "hashentry.h"
#include <string>
#include <iostream>

HashEntry::HashEntry(int key, string value) {
  this->key = key;
  this->value = value;
}

HashEntry::~HashEntry() {
}

int HashEntry::getKey() {
  return key;
}

string HashEntry::getValue() {
  return value;
}
