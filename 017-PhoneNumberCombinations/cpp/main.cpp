#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>> phone_codes = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    size_t n = pow(3, digits.length());
    vector<string> res;

    if (n < 3) {
      return res;
    }

    for (char c : digits) {
      size_t loops = 1;
      if (!res.empty()) {
        loops = res.size();
      }

      for (int i = 0; i < loops; i++) {
        string v;
        if (!res.empty()) {
          v = res.front();
          res.erase(res.begin());
        }

        for (char w : phone_codes[c]) {
          res.emplace_back(v+w);
        }
      }
    }

    return res;
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

int main() {
  string line;
  while (getline(cin, line)) {
    string str = stringToString(line);

    vector<string> ret = Solution().letterCombinations(str);

    for (string& out : ret) {
      cout << out << endl;
    }
  }
  return 0;
}