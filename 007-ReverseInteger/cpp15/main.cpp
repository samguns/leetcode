#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int positive_anchor = INT_MAX / 10;
    int negative_anchor = INT_MIN / 10;
    int res(0);

    while (x != 0) {
      int digit = x % 10;
      x /= 10;

      if (res > positive_anchor ||
          (res == positive_anchor && digit > 7)) {
        return 0;
      }

      if (res < negative_anchor ||
          (res == negative_anchor && digit < -8)) {
        return 0;
      }

      res = res * 10 + digit;
    }

    return res;
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