#include "hashdictionary.h"
#include <iostream>

using namespace std;

HashDictionary::HashDictionary() {
  DICT_SIZE = 128;
  dictionary = new HashEntry*[DICT_SIZE];
  for (int i = 0; i < DICT_SIZE; i++) {
    dictionary[i] = NULL;
  }
}

HashDictionary::HashDictionary(int size) {
  this->DICT_SIZE = size;
  dictionary = new HashEntry*[DICT_SIZE];
  for (int i = 0; i < DICT_SIZE; i++) {
    dictionary[i] = NULL;
  }
}

HashDictionary::~HashDictionary() {
  for (int i = 0; i < DICT_SIZE; i++) {
    if (dictionary[i] != NULL) {
      delete dictionary[i];
    }
  }
  delete[] dictionary;
}
 
string HashDictionary::get(string word) {
  int key = this->hashWord(word);
  int hash = (key % DICT_SIZE);
  while (dictionary[hash] != NULL && dictionary[hash]->getKey() != key) {
    hash = (hash + 1) % DICT_SIZE;
  }
  if (dictionary[hash] == NULL) {
    return NULL;
  } else {
    return dictionary[hash]->getValue();
  }
}

void HashDictionary::insert(string lang_1, string lang_2) {
  // TODO: for uppercase or title save another key
  int key_1 = this->hashWord(lang_1);
  int key_2 = this->hashWord(lang_2);
  int hash_1 = (key_1 % DICT_SIZE);
  int hash_2 = (key_2 % DICT_SIZE);
  while (dictionary[hash_1] != NULL && dictionary[hash_1]->getKey() != key_1) {
    hash_1 = (hash_1 + 1) % DICT_SIZE;
  }
  if (dictionary[hash_1] != NULL) {
    delete dictionary[hash_1];
  }
  while (dictionary[hash_1] != NULL && dictionary[hash_1]->getKey() != key_2) {
    hash_1 = (hash_1 + 1) % DICT_SIZE;
  }
  if (dictionary[hash_1] != NULL) {
    delete dictionary[hash_1];
  }
  dictionary[hash_1] = new HashEntry(key_1, lang_2, string("eng"));
  dictionary[hash_2] = new HashEntry(key_2, lang_1, string("rus"));
}

int HashDictionary::hashWord(string word) {
  int result = 0;

  for (int i = 0; i < word.length(); i++) {
    int tmp = static_cast<int>(word[i]);
    // TODO: знаки препинания, использовать: http://www.cplusplus.com/reference/cctype/
    // if (!isalpha(tmp)) {
    //   continue;
    // }
    result += static_cast<int>(tolower(tmp));
  }

  return (result % DICT_SIZE);
}

string HashDictionary::translate(string sentense) {
  vector<string> words = split(sentense, ' ');
  for(int i = 0; i < words.size(); i++) {
    cout << words[i] << endl;
  }
  return sentense;
}

vector<string> HashDictionary::split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}
