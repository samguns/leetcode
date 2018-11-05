class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        import sys
        nums_len = len(nums)
        ret = 0
        if nums_len <= 3:
            for n in nums:
                ret += n
            return ret

        nums.sort()

        min_diff = sys.maxsize
        for i in range(0, nums_len-2):
            a = nums[i]
            start = i + 1
            end = nums_len - 1

            while start < end:
                b = nums[start]
                c = nums[end]
                total = a + b + c
                diff = abs(total - target)
                if diff == 0:
                    return total

                if diff < min_diff:
                    min_diff = diff
                    ret = total

                if total < target:
                    start += 1
                else:
                    end -= 1

        return ret


def stringToIntegerList(input):
    import json
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

            ret = Solution().threeSumClosest(nums, target)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()