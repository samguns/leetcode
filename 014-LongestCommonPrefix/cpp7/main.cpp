#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string res;

    if (strs.empty()) {
      return res;
    }
    if (strs[0].empty()) {
      return res;
    }

    size_t min_len(INT_MAX);
    for (string& s : strs) {
      size_t length = s.length();
      if (length < min_len) {
        min_len = length;
      }
    }

    bool stop(false);
    for (int i = 0; i < min_len; i++) {
      char common_char(strs[0][i]);
      for (int j = 1; j < strs.size(); j++) {
        if (common_char != strs[j][i]) {
          stop = true;
          break;
        }
      }

      if (stop) {
        break;
      }

      res += common_char;
    }

    return res;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
    return !isspace(ch);
  }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
    return !isspace(ch);
  }).base(), input.end());
}

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

vector<string> stringToIntegerVector(string input) {
  vector<string> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(stringToString(input));
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(item);
  }
  return output;
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<string> strs = stringToIntegerVector(line);

    string out = Solution().longestCommonPrefix(strs);

    cout << out << endl;
  }
  return 0;
}