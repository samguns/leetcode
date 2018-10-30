#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    bool m[s.size()+1][p.size()+1];
    memo = (bool **)m;

    return dp(0, 0, s, p);
  }

 private:
  bool dp(int i, int j, string s, string p) {
    if (memo[i][j] != false) {
      return memo[i][j] == true;
    }

    bool ans;
    if (j == p.size()) {
      ans = (i == s.size());
    } else {
      bool first_match = (i < s.size() &&
          (p[j] == s[i] || p[j] == '.'));

      if (j+1 < p.size() && p[j+1] == '*') {
        ans = (dp(i, j+2, s, p) || first_match && dp(i+1, j, s, p));
      } else {
        ans = first_match && dp(i+1, j+1, s, p);
      }
    }

    memo[i][j] = ans;

    return ans;
  }

  bool **memo;
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

string boolToString(bool input) {
  return input ? "True" : "False";
}

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);
    getline(cin, line);
    string p = stringToString(line);

    bool ret = Solution().isMatch(s, p);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}