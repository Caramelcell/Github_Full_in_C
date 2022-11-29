//#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::istringstream;
using std::ostringstream;
using std::string;

void PrintStateBits(const istream& iss);
int GetInteger(const string& prompt);

void PrintStateBits(const istream& iss) {
  cout << "State bits:";
  cout << iss.good() ? "G" : "-";
  cout << iss.fail() ? "F" : "-";
  cout << iss.eof() ? "E" : "-";
  cout << iss.bad() ? "B" : "-";
  cout << "\n";
}
int GetInteger(const string& prompt) {
  while (true) {
    cout << prompt;
    string line;
    //cin >> line;
    /*if u give screen "3a",'3' will be read and 'a' will stay in buffer.
     *so if u enter ctrl+d in that time(give a eof),worst,The program will print
        prompt crazily without ending until you enter ctrl+c.

     ======================================================================

     *that is why >> with cin is a nightmare,we have 3 reason:
     *1.cin reads the entire line into the buffer but extracts
        whitespace-separated tokens.
     *2.Trash in the buffer will make cin not
        prompt the user for input at the right time.
     *3.when cin fails,all future cin operations fail too.

     ======================================================================
     *so maybe we should use getline
    */
    if (!getline(cin, line)) {
      throw domain_error("error");
    }
    istringstream iss(line);
    PrintStateBits(iss);

    int result;
    char trash;
    PrintStateBits(iss);
    if (iss >> result && !(iss >> trash)) {
      return result;
    }
  }
}

int main() {
  string prompt("plz input integer:");
  cout << GetInteger(prompt) << "\n";
}