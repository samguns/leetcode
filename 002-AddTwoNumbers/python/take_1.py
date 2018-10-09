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
        carry = 0
        result = ListNode(None)
        curr = result

        while (l1 is not None) or (l2 is not None):
            lhs, rhs = 0, 0
            if l1 is not None:
                lhs = l1.val
                l1 = l1.next

            if l2 is not None:
                rhs = l2.val
                l2 = l2.next

            sum = lhs + rhs + carry

            if sum >= 10:
                sum = sum % 10
                carry = 1
            else:
                carry = 0

            r = ListNode(sum)
            curr.next = r
            curr = r

        if carry == 1:
            r = ListNode(carry)
            curr.next = r

        return result.next


if __name__ == '__main__':
    nums1 = [6, 3, 4, 2]
    nums2 = [4, 6, 5]

    l1, l2, = None, None
    for _, v in enumerate(nums1):
        l = ListNode(v)
        l.next = l1
        l1 = l

    for _, v in enumerate(nums2):
        l = ListNode(v)
        l.next = l2
        l2 = l

    solution = Solution()
    ret = solution.addTwoNumbers(l1, l2)
    print(ret)