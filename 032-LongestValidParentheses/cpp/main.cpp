#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int maxlen = 0;

    for (int i = 0; i < s.length(); i++) {
      for (int j = i + 2; j <= s.length(); j += 2) {
        if (isValid(s.substr(i, j-i))) {
          maxlen = max(maxlen, j-i);
        }
      }
    }

    return maxlen;
  }

 private:
  bool isValid(string s) {
    stack<char> p_stack;

    for (char i : s) {
      if (i == '(') {
        p_stack.push(i);
      } else if (!p_stack.empty() && p_stack.top() == '(') {
        p_stack.pop();
      } else {
        return false;
      }
    }

    return p_stack.empty();
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

    int ret = Solution().longestValidParentheses(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}