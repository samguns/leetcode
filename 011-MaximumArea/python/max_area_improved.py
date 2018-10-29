class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        left = 0
        right = len(height) - 1
        found_min = 0

        while left < right:
            cur_min = min(height[left], height[right])
            if cur_min >= found_min:
                found_min = cur_min
                area = min(height[left], height[right]) * (right - left)
                if area > max_area:
                    max_area = area

            if height[left] < height[right]:
                left += 1
            elif height[left] == height[right]:
                left += 1
                right -= 1
            else:
                right -= 1

        return max_area


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
            height = stringToIntegerList(line)

            ret = Solution().maxArea(height)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()