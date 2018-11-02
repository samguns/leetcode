import json

class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        n = len(nums)
        if n < 3:
            return ret

        nums.sort()

        for i in range(0, n-2):
            a = nums[i]
            if i > 0 and nums[i-1] == a:
                continue

            first = i+1
            end = n-1
            while first < end:
                b = nums[first]
                c = nums[end]
                total = a+b+c

                if total == 0:
                    ret.append([a, b, c])
                    while first < end and b == nums[first]:
                        first += 1

                    while first < end and c == nums[end]:
                        end -= 1
                elif total < 0:
                    first += 1
                else:
                    end -= 1

        return ret


def stringToIntegerList(input):
    return json.loads(input)


def integerListToString(nums, len_of_list=None):
    if not len_of_list:
        len_of_list = len(nums)
    return json.dumps(nums[:len_of_list])


def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            nums = stringToIntegerList(line)

            ret = Solution().threeSum(nums)

            for r in ret:
                out = integerListToString(r)
                print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()