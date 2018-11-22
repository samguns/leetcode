#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int of_sign = 214748364;
    int ret(0);

    while (x) {
      int d = x % 10;
      if (ret > of_sign ||
         (ret == of_sign && d > 7)) {
        return 0;
      }
      if (ret < -of_sign ||
          (ret == -of_sign && d < -8)) {
        return 0;
      }

      ret = ret * 10 + d;
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