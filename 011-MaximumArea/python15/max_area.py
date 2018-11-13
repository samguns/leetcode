class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        left = 0
        right = n - 1
        max_area = 0

        while left < right:
            min_height = min(height[left], height[right])
            width = right - left
            area = min_height * width
            if area > max_area:
                max_area = area

            if height[left] < height[right]:
                left += 1
            elif height[left] > height[right]:
                right -= 1
            else:
                left += 1
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