#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x == 0) {
      return true;
    }
    if (x < 0) {
      return false;
    }
    if (x % 10 == 0) {
      return false;
    }

    int rev(0);
    while (x > rev) {
      rev = rev * 10 + (x % 10);
      x /= 10;
    }

    return (x == rev) || (x == rev/10);
  }
};

int stringToInteger(string input) {
  return stoi(input);
}

string boolToString(bool input) {
  return input ? "True" : "False";
}

int main() {
  string line;
  while (getline(cin, line)) {
    int x = stringToInteger(line);

    bool ret = Solution().isPalindrome(x);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}