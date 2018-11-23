#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    int ret(0);
    int sign(1);
    bool started(false);

    for (char& c : str) {
      if (started == false) {
        if (c == ' ') {
          continue;
        }

        if (c == '+') {
          started = true;
          continue;
        }

        if (c == '-') {
          sign = -1;
          started = true;
          continue;
        }

        started = true;
      }

      if (c < '0' || c > '9') {
        return ret;
      }

      int d = (c - '0') * sign;
      if (ret > 214748364 || (ret == 214748364 && d > 7)) {
        return 2147483647;
      }
      if (ret < -214748364 || (ret == -214748364 && d < -8)) {
        return -2147483648;
      }

      ret = ret * 10 + d;
    }

    return ret;
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

    int ret = Solution().myAtoi(str);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}