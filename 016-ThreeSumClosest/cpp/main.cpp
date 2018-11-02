#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    size_t n = nums.size();
    int ret(0);
    int min_diff(INT_MAX);
    if (n <= 3) {
      for (int& e : nums) {
        ret += e;
      }
      return ret;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n-2; i++) {
      int a = nums[i];

      int start = i + 1;
      size_t end = n - 1;
      while (start < end) {
        int b = nums[start];
        int c = nums[end];
        int sum = a + b + c;
        int diff = abs(target - sum);
        if (diff == 0) {
          return target;
        }

        if (diff < min_diff) {
          ret = sum;
          min_diff = diff;
        }

        if (sum < target) {
          start++;
        } else {
          end--;
        }
      }
    }

    return ret;
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

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);
    getline(cin, line);
    int target = stoi(line);

    int ret = Solution().threeSumClosest(nums, target);

    cout << to_string(ret) << endl;
  }
  return 0;
}