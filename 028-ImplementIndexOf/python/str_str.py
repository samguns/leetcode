class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        n = len(needle)
        if n == 0:
            return 0

        start = 0
        end = len(haystack) - 1

        ret = -1

        while (end - start) > (n - 2):
            left = haystack[start]
            right = haystack[end]
            if left != needle[0]:
                start += 1
            if right != needle[n-1]:
                end -= 1

            if left == needle[0] and right == needle[n-1]:
                remains = n - 2
                if remains == 0:
                    return start

                match = True
                ret = start
                for i in range(1, remains+1):
                    start += 1
                    if haystack[start] != needle[i]:
                        match = False
                        ret = -1
                        break

                if match == True and (end-start) == 1:
                    break

                end -= 1

        return ret


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
            haystack = stringToString(line);
            line = next(lines)
            needle = stringToString(line);

            ret = Solution().strStr(haystack, needle)

            out = str(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()