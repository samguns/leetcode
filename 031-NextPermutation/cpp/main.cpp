#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    size_t n = nums.size();
    if (n <= 1) {
      return;
    }

    int i = n - 1;
    while (i > 0) {
      if (nums[i - 1] < nums[i]) {
        break;
      }
      i--;
    }

    if (i > 0) {
      int j = i;
      while (j < n) {
        if (nums[i - 1] >= nums[j]) {
          break;
        }
        j++;
      }

      int tmp = nums[j - 1];
      nums[j - 1] = nums[i - 1];
      nums[i - 1] = tmp;
    }

    reverse(nums.begin()+i, nums.end());
  }
};


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

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for(int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    Solution().nextPermutation(nums);

    string out = integerVectorToString(nums);
    cout << out << endl;
  }
  return 0;
}