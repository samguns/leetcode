class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        combination = []
        self.generate("", combination, 0, 0, n)

        return combination

    def generate(self, current, result, open, close, max):
        if len(current) == 2*max:
            result.append(current)
            return

        if open < max:
            self.generate(current+'(', result, open+1, close, max)
        if close < open:
            self.generate(current+')', result, open, close+1, max)

        return


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
            n = stringToInt(line)

            ret = Solution().generateParenthesis(n)

            out = stringArrayToString(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()