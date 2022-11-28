//#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::ostringstream;
using std::string;
void PrintStateBits(const istream& iss);
int StringToInteger(const string& s);

void PrintStateBits(const istream& iss) {
  cout << "State bits:";
  cout << iss.good() ? "G" : "-";
  cout << iss.fail() ? "F" : "-";
  cout << iss.eof() ? "E" : "-";
  cout << iss.bad() ? "B" : "-";
  cout << "\n";
}
int StringToInteger(const string& s) {
  istringstream iss(s);
  // iss have 4 state bit : good bit/fail bit/eof bit/bad bit
  PrintStateBits(iss);

  int result;
  if (!(iss >> result)) throw std::domain_error("no value in beginning!\n");
  //== if(iss.fail()) throw std::domain_error("no value in beginning!\n");
  /*
   *most common one is type of mismatch(istringstream.fail())
   *if fail bit become 1 it means previous operation failed------> all future
   *operation frozen
   */
  char remain;
  if (iss >> remain) throw std::domain_error("more than a single valid int\n");
  //==if (!iss.fail()) throw std::domain_error("more than a single valid int\n");

  cout << result << "\n";
  PrintStateBits(iss);

  return result;
}

int main() {
  string s;
  while (cin >> s) {
    StringToInteger(s);
  }
}