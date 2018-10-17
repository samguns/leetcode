//
// Created by Sam on 10/17/2018.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t m = nums1.size();
    size_t n = nums2.size();
    vector<int>& A = nums1;
    vector<int>& B = nums2;

    if (m > n) {
      m = n;
      n = nums1.size();
      vector<int> tmp = A;
      A = nums2;
      B = tmp;
    }

    int imin = 0;
    int imax = m;
    int middle = (m + n + 1) / 2;

    do {
      int i = (imin + imax) / 2;
      int j = middle - i;

      if (i < m && A[i] < B[j-1]) {
        imin = i + 1;
      } else if (i > 0 && A[i-1] > B[j]) {
        imax = i - 1;
      } else {
        int max_of_left = 0;
        int min_of_right = 0;
        if (i == 0) {
          max_of_left = B[j-1];
        } else if (j == 0) {
          max_of_left = A[i-1];
        } else {
          max_of_left = max(A[i-1], B[j-1]);
        }

        if (((m+n) % 2) == 1) {
          return max_of_left;
        }

        if (i == m) {
          min_of_right = B[j];
        } else if (j == n) {
          min_of_right = A[i];
        } else {
          min_of_right = min(A[i], B[j]);
        }

        return (max_of_left + min_of_right) / 2.0;
      }
    } while (imin <= imax);
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
    vector<int> nums1 = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> nums2 = stringToIntegerVector(line);

    double ret = Solution().findMedianSortedArrays(nums1, nums2);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}