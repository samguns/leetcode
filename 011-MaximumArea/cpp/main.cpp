#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int max_area(0);
    int left(0);
    int right(height.size() - 1);
    int found_min(0);

    while (left < right) {
      int min_height = min(height[left], height[right]);
      if (min_height > found_min) {
        int area = min_height * (right - left);
        if (area > max_area) {
          max_area = area;
        }
      }

      if (height[left] < height[right]) {
        left++;
      } else if (height[left] == height[right]) {
        left++;
        right--;
      } else {
        right--;
      }
    }

    return max_area;
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
    vector<int> height = stringToIntegerVector(line);

    int ret = Solution().maxArea(height);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}