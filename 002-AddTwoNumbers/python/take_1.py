import sys

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """


if __name__ == '__main__':
    input = sys.stdin.read()
    nums1 = [3, 4, 2]
    nums2 = [4, 6, 5]

    l1 = ListNode(None)
    for _, v in enumerate(nums1):
        next = ListNode(v)
        l1.next = next
        l1 = next