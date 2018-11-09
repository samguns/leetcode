#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> combinations;
    string current;

    generate(current, 0, 0, combinations, n);

    return combinations;
  }

 private:
  void generate(const string& current, int open, int close, vector<string>& result, int max) {
    if (current.length() == 2*max) {
      result.emplace_back(current);
    }

    if (open < max) {
      generate(current+'(', open+1, close, result, max);
    }
    if (close < open) {
      generate(current+')', open, close+1, result, max);
    }
  }
};


int main() {
  string line;
  while (getline(cin, line)) {
    int n = stoi(line);

    vector<string> ret = Solution().generateParenthesis(n);

    for (string& out : ret) {
      cout << out << endl;
    }
  }
  return 0;
}