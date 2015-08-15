#include "hashdictionary.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  int N;
  cin >> N;
  HashDictionary dictionary(N * 4);

  // string key;
  // string value;
  // for (int i = 0; i < N; i++) {
  //   cin >> key >> value;
  //   dictionary.insert(key, value);
  // }

  // cout << "Find by key: ";
  string sentense("Not or not.");
  // TODO: read sentense with white-spaces
  // cin >> sentense;
  cout << dictionary.translate(sentense) << endl;

  // TODO: i18n текущего предложения

  return 0;
}
