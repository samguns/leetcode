class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        combination = []
        current = ""

        self.generateAll(current, 0, 0, n, combination)
        return combination

    def generateAll(self, current, open, close, max, result):
        if len(current) == 2 * max:
            result.append(current)
            return

        if open < max:
            self.generateAll(current+'(', open+1, close, max, result)
        if close < open:
            self.generateAll(current+')', open, close+1, max, result)


def stringToInt(input):
    return int(input)


def stringArrayToString(input):
    import json
    return json.dumps(input)


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
            n = int(line)

            ret = Solution().generateParenthesis(n)

            out = stringArrayToString(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()