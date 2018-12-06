import json

class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return -1
        if n == 1:
            if target == nums[0]:
                return 0
            else:
                return -1
        mid = int(n / 2)
        lo = 0
        hi = n - 1

        if target == nums[lo]:
            return lo
        if target == nums[mid]:
            return mid
        if target == nums[hi]:
            return hi

        ret = -1
        if nums[lo] < nums[mid]:
            if target < nums[lo]:
                ret = self.search(nums[mid+1:], target)
                if ret >= 0:
                    ret += (mid + 1)
            elif target < nums[mid]:
                ret = self.search(nums[lo:mid+1], target)
        else:
            if target < nums[mid]:
                ret = self.search(nums[lo:mid+1], target)
            else:
                ret = self.search(nums[mid+1:], target)
                if ret >= 0:
                    ret += (mid + 1)

        return ret


def stringToIntegerList(input):
    return json.loads(input)


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
            line = next(lines)
            target = int(line)

            ret = Solution().search(nums, target)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()