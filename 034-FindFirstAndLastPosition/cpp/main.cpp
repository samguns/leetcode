#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(vector<int>({-1, -1}));
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = (lo + hi) / 2;

    if (hi < 0) {
      return result;
    }

    if (target < nums[lo] || target > nums[hi]) {
      return result;
    }

    int left_index = searchExtremeIndex(nums, target, true);
    if (nums[left_index] != target) {
      return result;
    }

    result[0] = left_index;
    result[1] = searchExtremeIndex(nums, target, false) - 1;

    return result;
  }

 private:
  int searchExtremeIndex(vector<int>& nums, const int& target, bool is_left) {
    int lo = 0;
    int hi = nums.size();

    while (lo < hi) {
      int mid = (lo + hi) / 2;

      if ((target < nums[mid]) || (is_left && target == nums[mid])) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    return lo;
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
    getline(cin, line);
    int target = stringToInteger(line);

    vector<int> ret = Solution().searchRange(nums, target);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}