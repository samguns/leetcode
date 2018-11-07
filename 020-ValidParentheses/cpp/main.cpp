#include <iostream>
#include <string>
#include <cassert>
#include <stack>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    bool res(true);
    stack<char> pools;

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        pools.push(c);
        res = false;
      } else if (c == ')' || c == ']' || c == '}') {
        if (pools.empty()) {
          return false;
        }

        char pre_symbol = pools.top();

        if ((pre_symbol == '(' && c != ')') ||
            (pre_symbol == '[' && c != ']') ||
            (pre_symbol == '{' && c != '}')) {
          break;
        } else {
          res = true;
          pools.pop();
        }
      }
    }

    if (pools.empty()) {
      return res;
    }

    return false;
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