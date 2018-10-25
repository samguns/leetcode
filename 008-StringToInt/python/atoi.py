class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        result = 0
        sign = 1
        start = False
        positive_anchor = int(pow(2, 31) / 10)
        negative_anchor = -int(pow(2, 31) / 10)

        for c in str:
            if start == False:
                if c == ' ':
                    continue

                if c == '+':
                    start = True
                    continue

                if c == '-':
                    start = True
                    sign = -1
                    continue

                start = True

            if c < '0' or c > '9':
                break

            digit = int(c) * sign
            if result > positive_anchor or \
                (result == positive_anchor and digit > 7):
                return pow(2, 31) - 1

            if result < negative_anchor or \
                    (result == negative_anchor and digit < -8):
                return -pow(2, 31)

            result = result * 10 + digit

        return result



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
            s = stringToString(line)

            ret = Solution().myAtoi(s)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()