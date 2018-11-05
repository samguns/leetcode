#include <iostream>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    string T = preProcess(s);
    int n = T.length();
    int P[n];
    int C(0), R(0);

    memset(P, 0, n*sizeof(int));

    for (int i = 1; i < n-1; i++) {
      int i_mirror = 2 * C - i;

      if (R > i) {
        P[i] = min(R-i, P[i_mirror]);
      } else {
        P[i] = 0;
      }

      /**
       * Attemp to expand palindrome centered at i
       */
      while (T[i+1 + P[i]] == T[i-1 - P[i]]) {
        P[i]++;
      }

      /**
       * If palindrome centered at i expand past R,
       * adjust center based on expanded palindrome.
       */
      if (i + P[i] > R) {
        C = i;
        R = i + P[i];
      }
    }

    int maxLen(0);
    int centerIndex(0);
    for (int i = 1; i < n-1; i++) {
      if (P[i] > maxLen) {
        maxLen = P[i];
        centerIndex = i;
      }
    }

    return s.substr((centerIndex-1-maxLen)/2, maxLen);
  }

 private:
  string preProcess(string& s) {
    size_t n = s.length();
    if (n == 0) {
      return "^$";
    }

    string ret = "^";
    for (size_t i = 0; i < n; i++) {
      ret += "#" + s.substr(i, 1);
    }

    ret += "#$";
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
    string s = stringToString(line);

    string ret = Solution().longestPalindrome(s);

    string out = (ret);
    cout << out << endl;
  }
  return 0;
}