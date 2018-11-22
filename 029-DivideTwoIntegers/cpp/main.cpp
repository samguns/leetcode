#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == -2147483648 && divisor == -1) {
      return 2147483647;
    }

    int sign(1);
    if ((dividend < 0 && divisor > 0) ||
        (dividend > 0 && divisor < 0)) {
      sign = -1;
    }

    unsigned int N(0);
    if (dividend < 0) {
      N = abs(dividend);
    } else {
      N = dividend;
    }
    unsigned int D(0);
    if (divisor < 0) {
      D = abs(divisor);
    } else {
      D = divisor;
    }

    if (N < D) {
      return 0;
    }
    if (N == D) {
      return sign;
    }

    int n_bits(0);
    unsigned int n(N);
    while (n) {
      n_bits++;
      n >>= 1;
    }

    unsigned int Q(0), R(0);
    for (int i = n_bits-1; i >= 0; i--) {
      R <<= 1;
      unsigned int n_i = N & (1 << i);
      R |= (n_i >> i);
      if (R >= D) {
        R -= D;
        Q |= (1 << i);
      }
    }

    if (sign == -1) {
      return -Q;
    }

    return Q;
  }
};

int stringToInteger(string input) {
  return stoi(input);
}

int main() {
  string line;
  while (getline(cin, line)) {
    int dividend = stringToInteger(line);
    getline(cin, line);
    int divisor = stringToInteger(line);

    int ret = Solution().divide(dividend, divisor);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}