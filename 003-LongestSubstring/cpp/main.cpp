#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    size_t str_len = s.length();
    int start(0);
    int longest_len(0);
    unordered_map<char, int> char_map;

    for (int i = 0; i < str_len; i++) {
      char c = s[i];
      if (char_map.find(c) != char_map.end()) {
        if (char_map[c] >= start) {
          start = char_map[c] + 1;
          char_map[c] = i;
          continue;
        }
      }

      int len = (i - start) + 1;
      if (len > longest_len) {
        longest_len = len;
      }
      char_map[c] = i;
    }

    return longest_len;
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

    int ret = Solution().lengthOfLongestSubstring(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}