#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    vector<string> sub_vec(numRows);
    int row(0);
    bool up(false);

    for (char& c : s) {
      if (row == 0) {
        up = false;
      }

      if (row == (numRows - 1)) {
        up = true;
      }

      sub_vec[row].push_back(c);

      if (up) {
        row--;
      } else {
        row++;
      }
    }

    string result;
    for (int i = 0; i < numRows; i++) {
      result += sub_vec[i];
    }

    return result;
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

int stringToInteger(string input) {
  return stoi(input);
}

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);
    getline(cin, line);
    int numRows = stringToInteger(line);

    string ret = Solution().convert(s, numRows);

    string out = (ret);
    cout << out << endl;
  }
  return 0;
}