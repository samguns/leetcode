
class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        start, end = 0, 0

        for i in range(len(s)):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i+1)

            length = max(len1, len2)
            if length > (end - start):
                start = i - int((length - 1) / 2)
                end = i + int(length / 2)

        return s[start:end+1]


    def expandAroundCenter(self, s, left, right):
        L, R = left, right
        while (L >= 0) and (R < len(s)) and s[L] == s[R]:
            L -= 1
            R += 1

        return R - L - 1

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

            ret = Solution().longestPalindrome(s)

            out = (ret)
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()