class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p:
            return not s

        first_match = (len(s) != 0) and (s[0] == p[0] or p[0] == '.')

        if len(p) >= 2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or \
                   (first_match and self.isMatch(s[1:], p))
        else:
            return first_match and self.isMatch(s[1:], p[1:])


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
            line = next(lines)
            p = stringToString(line)

            ret = Solution().isMatch(s, p)

            out = (ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()