class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0

        for i in range(len(height)-1):
            for j in range(i+1, len(height)):
                min_height = min(height[i], height[j])
                width = j - i
                area = width * min_height
                if area > max_area:
                    max_area = area

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