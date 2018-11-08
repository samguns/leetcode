class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        res = 0
        start = False
        sign = 1
        positive_anchor = 214748364
        negative_anchor = -214748364

        for c in str:
            if not start:
                if c == ' ':
                    continue

                if c == '+':
                    start = True
                    continue

                if c == '-':
                    sign = -1
                    start = True
                    continue

                start = True

            if c < '0' or c > '9':
                break

            digit = int(c) * sign
            if res > positive_anchor or \
                    (res == positive_anchor and digit > 7):
                return 2147483647
            if res < negative_anchor or \
                    (res == negative_anchor and digit < -8):
                return -2147483648

            res = res * 10 + digit

        return res


def stringToString(input):
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
            _str = stringToString(line)

            ret = Solution().myAtoi(_str)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()