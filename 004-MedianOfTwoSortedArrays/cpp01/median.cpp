//
// Created by Sam on 10/23/2018.
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
      vector<int> tmp(A);
      A = B;
      B = tmp;
      m = n;
      n = B.size();
    }

    int middle = (m + n + 1) / 2;
    int imin = 0;
    int imax = m;
    double result(0);

    while (imin <= imax) {
      int i = (imin + imax) / 2;
      int j = middle - i;

      if ((i < m) && (B[j-1] > A[i])) {
        imin = i + 1;
      } else if ((i > 0) && (A[i-1] > B[j])) {
        imax = i - 1;
      } else {
        int left_max(0);
        int right_min(0);

        if (i == 0) {
          left_max = B[j-1];
        } else if (j == 0) {
          left_max = A[i-1];
        } else {
          left_max = max(A[i-1], B[j-1]);
        }

        if (((m+n) % 2) == 1) {
          result = left_max;
          break;
        }

        if (i == m) {
          right_min = B[j];
        } else if (j == n) {
          right_min = A[i];
        } else {
          right_min = min(A[i], B[j]);
        }

        result = (left_max + right_min) / 2.0;
        break;
      }
    }

    return result;
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