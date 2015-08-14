#include "hashdictionary.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  int N;
  cin >> N;
  HashDictionary dictionary(N * 4);

  string key;
  string value;
  for (int i = 0; i < N; i++) {
    cin >> key >> value;
    dictionary.insert(key, value);
  }

  cout << "Find by key: ";
  cin >> key;
  // TODO: проверка на получение слова (NULL)
  cout << dictionary.get(key) << endl;

  // TODO: i18n текущего предложения

  return 0;
}
