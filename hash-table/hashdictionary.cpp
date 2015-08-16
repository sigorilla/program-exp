#include "hashdictionary.h"
#include <iostream>
#include "ctype.h"

const int DICT_SIZE = 256;

using namespace std;

HashDictionary::HashDictionary() {
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
    return word;
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
  int p = 73;

  for (int i = 0; i < word.length(); i++) {
    // int tmp = static_cast<int>(word[i]);
    // TODO: знаки препинания, использовать: http://www.cplusplus.com/reference/cctype/
    // if (!isalpha(tmp)) {
    //   continue;
    // }
    result += static_cast<int>(tolower(word[i])) * p;
    p *= p;
  }

  return abs(result) % DICT_SIZE;
}

string HashDictionary::translate(string sentense) {
  string result = "";
  vector<string> words = split(sentense, ' ');
  for(int i = 0; i < words.size(); i++) {
    // cout << words[i] << endl;
    result += get(words[i]);
  }
  return result;
}

vector<string> HashDictionary::split(string s, char delim) {
  vector<string> elems;
  string tmp = "";
  for (int i = 0; i < s.length(); i++) {
    if (ispunct(s[i]) || isspace(s[i])) {
      if (tmp != "") {
        elems.push_back(tmp);
      }
      tmp = s[i];
      elems.push_back(tmp);
      tmp = "";
    } else {
      tmp += s[i];
    }
  }
  if (tmp != "") {
    elems.push_back(tmp);
  }
  return elems;
}
