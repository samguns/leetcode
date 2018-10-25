class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        rev = 0
        origin = x
        origin_2 = x * 2
        while x != 0:
            rev = rev * 10 + (x%10)
            x = int(x/10)

        if (origin + rev) == origin_2:
            return True

        return False


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
            x = int(line)

            ret = Solution().isPalindrome(x)

            out = (ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()