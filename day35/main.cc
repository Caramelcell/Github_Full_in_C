#include <ctype.h>
#include <math.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::string;
using std::vector;

string FileToString(ifstream&);
// map<string, int> FreqAllWord(const string&);
map<string, int> FreqWord(const vector<string>&, const string&);
double VectorLen(map<string, int>& vec);
double Similarity(const string& text1, const string& text2);

auto DelPunctuation = [](auto a) {
  if (!isalpha(a)) a = ' ';
  return a;
};

vector<string> function_word = {"the", "at", "are", "where", "when"};

string FileToString(ifstream& file) {
  string line;
  string ret = "";
  while (getline(file, line)) {
    std::transform(line.begin(), line.end(), line.begin(), DelPunctuation);
    std::transform(line.begin(), line.end(), line.begin(), tolower);
    ret += line + " ";
  }
  return ret;
}

// map<string, int> FreqAllWord(const string& text) {
//   map<string, int> freq_all_words;
//   string buf;
//   istringstream iss(text);
//   while (iss >> buf) {
//     freq_all_words[buf]++;
//   }
//   return freq_all_words;
// }

map<string, int> FreqWord(const vector<string>& function_word,
                          const string& text) {
  map<string, int> freq_words;
  for (auto i : function_word) {
    freq_words.insert({i, 0});
  }  //现阶段去掉这个手动初始化反而会降低速度
  string buf;
  istringstream iss(text);
  while (iss >> buf) {
    // for (auto word : function_word) {
    //   if (buf == word) {
    //     freq_words[buf]++;
    //   }
    // }  // STL比你快
    if (std::find(function_word.begin(), function_word.end(), buf) !=
        function_word.end()) {
      freq_words[buf]++;
    }
  }
  return freq_words;
}

double VectorLen(map<string, int>& vec) {
  double ret = 0;
  for (auto i : vec) {
    ret += i.second * i.second;
  }
  return sqrt(ret);
}

double Similarity(const string& text1, const string& text2) {
  map<string, int> freq_word1 = FreqWord(function_word, text1);
  map<string, int> freq_word2 = FreqWord(function_word, text2);
  auto i1 = freq_word1.begin();
  auto i2 = freq_word2.begin();
  double dotpro = 0;
  while (i1 != freq_word1.end() && i2 != freq_word2.end()) {
    dotpro += (i1->second) * (i2->second);
    ++i1;
    ++i2;
  }
  return dotpro / (VectorLen(freq_word1) * VectorLen(freq_word2));
}

int main(int argc, char* argv[]) {
  ifstream file1(argv[1]);
  ifstream file2(argv[2]);

  clock_t start, end1,end2;
  start = clock();

  string str_file1 = FileToString(file1);
  string str_file2 = FileToString(file2);

  end1 = clock();
  cout << (end1 - start) << endl;

  double result = Similarity(str_file1, str_file2);

  end2 = clock();
  cout << (end2 - end1) << endl;

  cout << result << endl;
  return 0;
}
