#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int ret(0);
    int overflow_anchor = INT_MAX / 10;
    int overflow_anchor_m = INT_MIN / 10;

    while (x != 0) {
      int m = x % 10;

      if ((ret > overflow_anchor) ||
          (ret == overflow_anchor && m > 7)) {
        return 0;
      }

      if ((ret < overflow_anchor_m) ||
          (ret == overflow_anchor_m && m < -8)) {
        return 0;
      }

      ret = ret * 10 + m;
      x /= 10;
    }

    return ret;
  }
};

int stringToInteger(string input) {
  return stoi(input);
}

int main() {
  string line;
  while (getline(cin, line)) {
    int x = stringToInteger(line);

    int ret = Solution().reverse(x);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}