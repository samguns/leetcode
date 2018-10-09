#include <stdio.h>
int main() {
  unsigned int x = 5, y = 6, sum, carry;
  sum = x ^ y;
  carry = x & y;

  while (carry != 0) {
    carry = carry << 1;
    x = sum;
    y = carry;
    sum = x ^ y;
    carry = x & y;
  }

  printf("%u\n", sum);
  return 0;
}