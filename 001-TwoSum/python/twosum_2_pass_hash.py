import sys


class Solution:
    def twoSum(self, nums, target):
        """
        :param nums: List[int]
        :param target: int
        :return: List[int]
        """
        complement = {}

        for i in range(len(nums)):
            complement.update({nums[i]: i})

        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in complement:
                if i != complement[comp]:
                    return [i, complement[comp]]

        return "No such solution."


if __name__ == '__main__':
    input = sys.stdin.read()
    *nums, target = list(map(int, input.split()))
    solution = Solution()
    ret = solution.twoSum(nums, target)
    print(ret)