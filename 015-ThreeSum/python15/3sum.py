import json

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        if n < 3:
            return []

        nums.sort()

        ret = []
        for i in range(n):
            a = nums[i]
            if i > 0 and a == nums[i-1]:
                continue

            start = i+1
            end = n-1
            while start < end:
                b = nums[start]
                c = nums[end]
                total = a + b + c
                if total == 0:
                    ret.append([a, b, c])
                    while start < end and b == nums[start]:
                        start += 1

                    while start < end and c == nums[end]:
                        end -= 1

                elif total < 0:
                    start += 1
                else:
                    end -= 1

        return ret


def stringToIntegerList(input):
    return json.loads(input)


def int2dArrayToString(input):
    return json.dumps(input)


def main():
    import io
    import sys
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            nums = stringToIntegerList(line)

            ret = Solution().threeSum(nums)

            out = int2dArrayToString(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()