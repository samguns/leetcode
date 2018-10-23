class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if (x < -pow(2, 31) or x > (pow(2, 31) - 1)):
            return 0

        if -10 < x < 10:
            return x

        is_negative = False
        if x < 0:
            is_negative = True
            #x = abs(x)

        ret = 0
        while x != 0:
            ret = ret * 10 + (x % 10)
            x = int(x / 10)

        if is_negative:
            ret *= -1

        if (ret < -pow(2, 31) or ret > (pow(2, 31) - 1)):
            return 0

        return ret


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

            ret = Solution().reverse(x)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()