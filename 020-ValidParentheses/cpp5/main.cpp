#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s.empty()) {
      return true;
    }

    stack<char> opens;
    for (char& c : s) {
      if (c == '(' || c == '[' || c == '{') {
        opens.push(c);
      } else if (c == ')' || c == ']' || c == '}') {
        if (opens.empty()) {
          return false;
        }
        char& open = opens.top();
        opens.pop();
        if ((open == '(' && c != ')') ||
            (open == '[' && c != ']') ||
            (open == '{' && c != '}')) {
          return false;
        }
      }
    }

    return opens.empty();
  }
};

string stringToString(string input) {
  assert(input.length() >= 2);
  string result;
  for (int i = 1; i < input.length() -1; i++) {
    char currentChar = input[i];
    if (input[i] == '\\') {
      char nextChar = input[i+1];
      switch (nextChar) {
        case '\"': result.push_back('\"'); break;
        case '/' : result.push_back('/'); break;
        case '\\': result.push_back('\\'); break;
        case 'b' : result.push_back('\b'); break;
        case 'f' : result.push_back('\f'); break;
        case 'r' : result.push_back('\r'); break;
        case 'n' : result.push_back('\n'); break;
        case 't' : result.push_back('\t'); break;
        default: break;
      }
      i++;
    } else {
      result.push_back(currentChar);
    }
  }
  return result;
}

string boolToString(bool input) {
  return input ? "True" : "False";
}

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);

    bool ret = Solution().isValid(s);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}