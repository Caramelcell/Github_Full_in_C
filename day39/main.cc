#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    //class Solution {
    //public:
    //    bool checkIfPangram(string sentence) {
    //        unsigned int dig_map = -1;
    //        unsigned int right_result = dig_map << 26;
    //        for (auto i = sentence.begin(); i != sentence.end(); ++i) {
    //            dig_map &= (1 << (static_cast<int>(*i) - 97)) ^ (-1);
    //        }
    //        return !(dig_map ^ right_result);
    //    }
    //};
    class Solution {
    public:
        int canBeTypedWords(string text, string brokenLetters) {
            unsigned vaild_letters = (1 << 26) - 1;
            for (auto i : brokenLetters) {
                vaild_letters ^= 1 << (i - 'a');
            }
            string word;
            int count = 0;
            std::istringstream iss{ text };
            while (iss >> word) {
                int flag = 0;
                for (auto i : word) {
                    unsigned res = 1 << (i - 'a');
                    if (!(res & vaild_letters)) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) {
                    continue;
                }
                else {
                    ++count;
                }
            }
            return count;
        }
    };
    Solution test;
    string str = "abc def ghi jk";
    cout << test.canBeTypedWords(str,"a") << endl;
}