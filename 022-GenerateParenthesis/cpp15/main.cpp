#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n <= 0) {
      return result;
    }

    string current;
    generate(current, result, 0, 0, n);

    return result;
  }

 private:
  void generate(const string& current, vector<string>& combination, int open, int close, int n) {
    if (current.length() == 2 * n) {
      combination.push_back(current);
      return;
    }

    if (open < n) {
      generate(current+'(', combination, open+1, close, n);
    }
    if (close < open) {
      generate(current+')', combination, open, close+1, n);
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