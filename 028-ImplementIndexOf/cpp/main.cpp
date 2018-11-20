#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    size_t n = haystack.length();
    size_t m = needle.length();
    if (m == 0) {
      return 0;
    }

    vector<int> next(m);
    int j(-1);
    for (int i = 0; i < m; i++) {
      if (i == 0) {
        next[i] = -1;
      } else if (needle[i] != needle[j]) {
        next[i] = j;
      } else {
        next[i] = next[j];
      }

      while (j >= 0 && needle[i] != needle[j]) {
        j = next[j];
      }

      j++;
    }

    int i;
    for (i = 0, j = 0; i < n && j < m; i++) {
      while (j >= 0 && haystack[i] != needle[j]) {
        j = next[j];
      }

      j++;
    }

    if (j == m) {
      return i - m;
    }

    return -1;
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
    string haystack = stringToString(line);
    getline(cin, line);
    string needle = stringToString(line);

    int ret = Solution().strStr(haystack, needle);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}