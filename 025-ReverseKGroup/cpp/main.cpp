#include <utility>

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (k == 1) {
        return head;
      }
      ListNode dummy(0);
      ListNode *front = &dummy;
      ListNode *left = head;
      ListNode *right = head;
      dummy.next = head;

      while (true) {
        int cnt(0);
        while (right != nullptr && cnt < k) {
          right = right->next;
          cnt++;
        }

        if (cnt == k) {
          ListNode *pre = right;
          ListNode *cur = left;
          ListNode *next(nullptr);

          for (int i = 0; i < k; i++) {
            next = cur->next;

            cur->next = pre;

            pre = cur;
            cur = next;
          }

          front->next = pre;
          front = left;
          left = right;
        } else {
          return dummy.next;
        }
      }
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(std::move(input));

    // Now convert that list into linked list
  auto * dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(const string &input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int k = stringToInteger(line);

        ListNode* ret = Solution().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}