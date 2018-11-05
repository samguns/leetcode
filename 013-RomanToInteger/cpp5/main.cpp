#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> roman_table = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int res(0);
    int prev(0);

    for (char c : s) {
      int curr = roman_table[c];
      if (curr > prev) {
        res += (curr - 2 * prev);
      } else {
        res += curr;
      }

      prev = curr;
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
    string s = stringToString(line);

    int ret = Solution().romanToInt(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}