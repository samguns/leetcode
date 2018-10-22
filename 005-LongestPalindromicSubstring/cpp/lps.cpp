//
// Created by Sam on 2018/10/21.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int start = 0;
    int end = 0;

    for (int i = 0; i < s.length(); i++) {
      int len1 = expandAroundCenter(s, i, i);
      int len2 = expandAroundCenter(s, i, i+1);

      int len = max(len1, len2);
      if (len > (end - start)) {
        start = i - (len - 1) / 2;
        end = i + len / 2;
      }
    }

    return s.substr(start, (end-start+1));
  }

 private:
  int expandAroundCenter(string s, int left, int right) {
    int L = left;
    int R = right;

    while ((L >= 0) && (R < s.length()) && (s.at(L) == s.at(R))) {
      L--;
      R++;
    }

    return (R - L - 1);
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