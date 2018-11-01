#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    size_t n = nums.size();
    if (n < 3) {
      return ret;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n-2; i++) {
      int a = nums[i];
      if (i > 0) {
        if (nums[i-1] == a) {
          continue;
        }
      }

      int start = i + 1;
      int end = n-1;

      while (start < end) {
        int b = nums[start];
        int c = nums[end];

        int result = a+b+c;
        if (result == 0) {
          ret.emplace_back(vector<int>{a, b, c});
          do {
            start++;
          } while ((start < end) && (nums[start] == b));

          do {
            end--;
          } while ((start < end) && (nums[end] == c));
        } else if (result < 0) {
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

    vector<vector<int>> ret = Solution().threeSum(nums);

    for (vector<int>& v : ret) {
      string out = integerVectorToString(v);
      cout << out << endl;
    }
  }
  return 0;
}