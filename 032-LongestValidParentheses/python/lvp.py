class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        maxlen = 0
        if n < 2:
            return maxlen

        dp = [0 for _ in range(n)]

        for i in range(1, n):
            if s[i] == ')':
                if s[i-1] == '(':
                    if (i-2) < 0:
                        dp[i] = 2
                    else:
                        dp[i] = dp[i-2] + 2
                elif s[i-1] == ')':
                    if (i - dp[i-1] - 1) >= 0:
                        prev = s[i - dp[i-1] - 1]
                        if prev == '(':
                            if (i - dp[i-1] - 2) < 0:
                                dp[i] = dp[i-1] + 2
                            else:
                                dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2

                maxlen = max(maxlen, dp[i])

        return maxlen


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

            ret = Solution().longestValidParentheses(s)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()