#include <iostream>
#include <list>
#include <sstream>

using namespace std;

list<string> split(const string &line) {
  list<string> tokens;
  string token;
  istringstream tokenStream(line);
  while (tokenStream >> token) {
    tokens.push_back(token);
  }
  return tokens;
}

int main() {
  string str = "apple banana cherry melon";
  // std::getline(cin, line);

  list<string> wordList = split(str);

  cout << "List of words:" << endl;
  for (const string &word : wordList) {
    cout << word << endl;
  }

  return 0;
}