#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int min_diff(INT_MAX);
    int res(0);
    size_t n = nums.size();
    if (n < 3) {
      return res;
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n-2; i++) {
      int a = nums[i];

      int start = i + 1;
      int end = n - 1;
      while (start < end) {
        int b = nums[start];
        int c = nums[end];

        int total = a + b + c;
        int diff = abs(total - target);
        if (diff == 0) {
          return total;
        }

        if (diff < min_diff) {
          min_diff = diff;
          res = total;
        }

        if (total < target) {
          start++;
        } else {
          end--;
        }
      }
    }

    return res;
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

int stringToInteger(string input) {
  return stoi(input);
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);
    getline(cin, line);
    int target = stringToInteger(line);

    int ret = Solution().threeSumClosest(nums, target);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}