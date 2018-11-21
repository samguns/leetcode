#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    size_t n = s.length();
    size_t cnt = words.size();
    if (n <= 0 || cnt <= 0) {
      return ans;
    }

    unordered_map<string, int> dict;
    for (int i = 0; i < cnt; i++) {
      dict[words[i]]++;
    }

    size_t w1 = words[0].length();
    if (w1 > n) {
      return ans;
    }
    for (int i = 0; i < w1; i++) {
      int left = i, count = 0;
      unordered_map<string, int> tdict;
      for (int j = i; j <= n-w1; j += w1) {
        string str = s.substr(j, w1);

        if (dict.count(str)) {
          tdict[str]++;

          if (tdict[str] <= dict[str]) {
            count++;
          } else {
            while (tdict[str] > dict[str]) {
              string str1 = s.substr(left, w1);
              tdict[str1]--;

              if (tdict[str1] < dict[str1]) {
                count--;
              }

              left += w1;
            }
          }

          if (count == cnt) {
            ans.push_back(left);
            tdict[s.substr(left, w1)]--;
            count--;
            left += w1;
          }
        } else {
          tdict.clear();
          count = 0;
          left = j + w1;
        }
      }
    }

    return ans;
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

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
    return !isspace(ch);
  }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
    return !isspace(ch);
  }).base(), input.end());
}

vector<string> stringToStringVector(string input) {
  vector<string> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stringToString(item));
  }
  return output;
}

int main() {
  string line;
  while (getline(cin, line)) {
    string str = stringToString(line);
    getline(cin, line);
    vector<string> words = stringToStringVector(line);

    vector<int> ret = Solution().findSubstring(str, words);

    for (int& out : ret) {
      cout << out << endl;
    }
  }
  return 0;
}
