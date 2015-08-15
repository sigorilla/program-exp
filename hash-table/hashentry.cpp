#include "hashentry.h"
#include <string>
#include <iostream>

HashEntry::HashEntry(int key, string value, string lang)
    : key(key),
      value(value),
      lang(lang) {
}

HashEntry::~HashEntry() {
}

int HashEntry::getKey() {
  return key;
}

string HashEntry::getValue() {
  return value;
}

string HashEntry::getLang() {
  return lang;
}
