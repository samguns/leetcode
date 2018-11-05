#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    return longestPalindromeDP(s);
  }

 private:
  string longestPalindromeDP(string& s) {
    int n = s.length();
    int longestBegin(0);
    int maxLen(1);
    bool table[n][n] = {false};

    for (int i = 0; i < n; i++) {
      table[i][i] = true;
    }

    for (int i = 0; i < n-1; i++) {
      if (s[i] == s[i+1]) {
        table[i][i+1] = true;
        longestBegin = i;
        maxLen = 2;
      }
    }

    for (int len = 3; len <= n; len++) {
      for (int i = 0; i < n-len+1; i++) {
        int j = i+len-1;
        if (s[i] == s[j] && table[i+1][j-1]) {
          table[i][j] = true;
          longestBegin = i;
          maxLen = len;
        }
      }
    }

    return s.substr(longestBegin, maxLen);
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