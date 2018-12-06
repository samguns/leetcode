#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      size_t lo = 0;
      size_t hi = nums.size();

      while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        int num(0);
        if ((nums[mid] < nums[0]) == (target < nums[0])) {
          num = nums[mid];
        } else {
          if (target < nums[0]) {
            num = target - 1;
          } else {
            num = target + 1;
          }
        }

        if (num < target) {
          lo = mid + 1;
        } else if (num > target) {
          hi = mid;
        } else {
          return mid;
        }
      }

      return -1;
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

    int ret = Solution().search(nums, target);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}