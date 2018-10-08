import sys


class Solution:
    def twoSum(self, nums, target):
        """
        :param nums: List[int]
        :param target: int
        :return: List[int]
        """
        complements = {}

        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in complements:
                return [complements[comp], i]

            complements.update({nums[i]: i})

        return "No such solution."


if __name__ == '__main__':
    input = sys.stdin.read()
    *nums, target = list(map(int, input.split()))
    solution = Solution()
    ret = solution.twoSum(nums, target)
    print(ret)