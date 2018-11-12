#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      size_t n = lists.size();
      if (lists.empty()) {
        return nullptr;
      }
      if (n == 1) {
        return lists[0];
      }

      size_t middle = n / 2;
      vector<ListNode*> left(lists.begin(), lists.begin() + middle);
      vector<ListNode*> right(lists.begin() + middle, lists.end());
      ListNode *l1 = mergeKLists(left);
      ListNode *l2 = mergeKLists(right);

      return mergeTwoLists(l1, l2);
    }

 private:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      ListNode dummy(0);
      ListNode *merge = &dummy;

      while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
          merge->next = l1;
          l1 = l1->next;
        } else {
          merge->next = l2;
          l2 = l2->next;
        }

        merge = merge->next;
      }

      if (l1 == nullptr) {
        merge->next = l2;
      }
      if (l2 == nullptr) {
        merge->next = l1;
      }

    return dummy.next;
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
  vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode* dummyRoot = new ListNode(0);
  ListNode* ptr = dummyRoot;
  for(int item : list) {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
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
    vector<ListNode*> lists;
    ListNode* l1 = stringToListNode(line);
    lists.push_back(l1);

    getline(cin, line);
    ListNode* l2 = stringToListNode(line);
    lists.push_back(l2);

    getline(cin, line);
    ListNode* l3 = stringToListNode(line);
    lists.push_back(l3);

    ListNode* ret = Solution().mergeKLists(lists);

    string out = listNodeToString(ret);
    cout << out << endl;
  }
  return 0;
}