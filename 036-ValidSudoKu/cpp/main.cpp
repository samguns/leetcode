//
// Created by sam on 2021/3/9.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> row_check(9, vector<int>(9, 0));
    vector<vector<int>> col_check(9, vector<int>(9, 0));
    vector<vector<int>> box_check(9, vector<int>(9, 0));

    for (int row = 0; row < board.size(); row++) {
      for (int col = 0; col < board[row].size(); col++) {
        if (board[row][col] == '.') {
          continue;
        }

        int num = board[row][col] - 0x30;
        // Row check
        if (num == row_check[row][num - 1]) {
          return false;
        } else {
          row_check[row][num - 1] = num;
        }

        // Col check
        if (num == col_check[col][num - 1]) {
          return false;
        } else {
          col_check[col][num - 1] = num;
        }

        // Sub Box check
        int subbox_row = (row / 3) * 3 + col / 3;
        if (num == box_check[subbox_row][num - 1]) {
          return false;
        } else {
          box_check[subbox_row][num - 1] = num;
        }
      }

    }
    return true;
  };
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

vector<char> stringToCharVector(string &input) {
  vector<char> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(2, input.length() - 3);

  stringstream ss;
  ss.str(input);
  string item;

  while (getline(ss, item, ',')) {
    output.push_back(item.at(1));
  }

  return output;
}

int main() {
  string line;
  vector<vector<char>> sudoku_board;
  while (getline(cin, line, ']')) {
    if (line.length() < 3) {
      break;
    }
    sudoku_board.push_back(stringToCharVector(line));
  }

  bool ret = Solution().isValidSudoku(sudoku_board);
  cout << (ret ? "True" : "False") << endl;

  return 0;
}
