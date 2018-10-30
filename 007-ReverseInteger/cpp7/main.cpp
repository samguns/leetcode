#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int positive_overflow_anchor = INT_MAX / 10;
    int negative_overflow_anchor = INT_MIN / 10;

    int ret(0);

    while (x != 0) {
      int digit = x % 10;
      x /= 10;

      if ((ret > positive_overflow_anchor) ||
          (ret == positive_overflow_anchor && digit > 7)) {
        ret = 0;
        break;
      }

      if ((ret < negative_overflow_anchor) ||
          (ret == negative_overflow_anchor && digit < -8)) {
        ret = 0;
        break;
      }

      ret = ret * 10 + digit;
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