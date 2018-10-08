import sys


class Solution:
    def twoSum(self, nums, target):
        """
        :param nums: List[int]
        :param target: int
        :return: List[int]
        """
        result = [-1] * 2

        for i in range(len(nums)):
            result[0] = i

            for j in range(i + 1, len(nums)):
                sum = nums[i] + nums[j]
                if sum == target:
                    result[1] = j
                    return result

        return result


if __name__ == '__main__':
    input = sys.stdin.read()
    *nums, target = list(map(int, input.split()))
    solution = Solution()
    ret = solution.twoSum(nums, target)
    print(ret)