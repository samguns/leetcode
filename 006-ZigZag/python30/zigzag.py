class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s

        vec = ["" for _ in range(numRows)]
        up = False
        row = 0

        for c in s:
            if row == 0:
                up = False

            if row == numRows - 1:
                up = True

            vec[row] += c

            if up == True:
                row -= 1
            else:
                row += 1

        res = ""
        for sub_vec in vec:
            res += sub_vec
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
            s = stringToString(line);
            line = next(lines)
            numRows = int(line);

            ret = Solution().convert(s, numRows)

            out = (ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()