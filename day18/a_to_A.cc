#include "main.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void UppercaseConvert() {
  string words;
  vector<string> sentence;
  while (cin >> words) {  // ctrl + D break the loop
    sentence.push_back(words);
  }
  // for (auto i = sentence.size(); i > 0; --i) {
  //   for (auto j = sentence[i - 1].size(); j > 0; --j) {
  //     sentence[i - 1][j - 1] -= 32;
  //   }
  // }
  for (auto i = sentence.begin(); i != sentence.end(); ++i) {
    for (auto j = i->begin(); j != i->end(); j++) {
      *j -= 32;
    }
  }
  for (auto i : sentence) {
    cout << i << endl;
  }
}