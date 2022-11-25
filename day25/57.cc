#include "main.h"

namespace {
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

int NewFamily(map<string, vector<string>>& table, const string last_name,
              const vector<string> fml_members = vector<string>()) {
  if (table.find(last_name) == table.end()) {
    table.insert(pair<string, vector<string>>(last_name, fml_members));
    return 0;
  } else {
    cout << "its exist,plz use AddMember" << endl;
    return -1;
  }
}
int AddMember(map<string, vector<string>>& table, const string last_name,
              const string fml_member) {
  if (table.find(last_name) != table.end()) {
    table[last_name].push_back(fml_member);
    return 0;
  } else {
    cout << "cant find this family in table,try use NewFamily" << endl;
    return -1;
  }
}
void PrintTable(map<string, vector<string>>& table) {
  for (auto i = table.begin(); i != table.end(); ++i) {
    cout << (*i).first << ":";
    PrintContainer((*i).second);
  }
  cout << "---------------------------------" << endl;
}
}  // namespace

int Question57() {
  map<string, vector<string>> rgs_table;
  string last_name1("zhao");
  string last_name2("qian");
  string last_name3("sun");
  vector<string> fml_1_members{"san", "si", "wu"};
  vector<string> fml_2_members{"zhuang"};

  AddMember(rgs_table, last_name1, "san");
  PrintTable(rgs_table);
  NewFamily(rgs_table, last_name1, fml_1_members);
  PrintTable(rgs_table);
  NewFamily(rgs_table, last_name2, fml_2_members);
  PrintTable(rgs_table);
  NewFamily(rgs_table, last_name3);
  PrintTable(rgs_table);
  AddMember(rgs_table, last_name3, "he");
  PrintTable(rgs_table);

  return 0;
}