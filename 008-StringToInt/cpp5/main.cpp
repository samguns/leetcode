#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    int sign(1);
    int positive_overflow_check = INT_MAX / 10;
    int negative_overflow_check = INT_MIN / 10;
    bool start(false);
    int ret(0);

    for (char c : str) {
      if (!start) {
        if (c == ' ') {
          continue;
        }

        if (c == '+') {
          start = true;
          continue;
        }

        if (c == '-') {
          start = true;
          sign = -1;
          continue;
        }

        start = true;
      }

      if (c < '0' || c > '9') {
        break;
      }

      int digit = (c - '0') * sign;
      if ((ret > positive_overflow_check) ||
          (ret == positive_overflow_check && digit > 7)) {
        ret = INT_MAX;
        break;
      }

      if ((ret < negative_overflow_check) ||
          (ret == negative_overflow_check && digit < -8)) {
        ret = INT_MIN;
        break;
      }

      ret = ret * 10 + digit;
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