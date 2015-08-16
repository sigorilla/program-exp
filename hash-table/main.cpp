#include "hashdictionary.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  int N;
  cin >> N; // N <= 128
  HashDictionary dictionary;

  string key;
  string value;
  for (int i = 0; i < N; i++) {
    cin >> key >> value;
    dictionary.insert(key, value);
  }

  cout << "Sentense for translate: " << endl;
  string sentense;
  cin.ignore();
  getline(cin, sentense);
  // TODO: read sentense with white-spaces
  // cin >> sentense;
  cout << dictionary.translate(sentense) << endl;

  // TODO: i18n текущего предложения

  return 0;
}
