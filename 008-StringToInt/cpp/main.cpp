#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    int sign(1);
    bool start(false);
    int result(0);
    int positive_overf_anchor = INT_MAX / 10;
    int negative_overf_anchor = INT_MIN / 10;

    for (char& c : str) {
      if (!start) {
        if (c == ' ') {
          continue;
        }
        if (c == '-') {
          start = true;
          sign = -1;
          continue;
        }
        if (c == '+') {
          start = true;
          continue;
        }

        start = true;
      }

      if (c < '0' || c > '9') {
        break;
      }

      int digit = sign * (c - '0');
      if ((result > positive_overf_anchor) ||
          (result == positive_overf_anchor && digit > 7)) {
        return INT_MAX;
      }

      if ((result < negative_overf_anchor) ||
          (result == negative_overf_anchor && digit < -8)) {
        return INT_MIN;
      }

      result = result * 10 + digit;
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