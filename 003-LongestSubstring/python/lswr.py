
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_map = {}
        start = 0
        longest_len = 0

        for i, c in enumerate(s):
            if c in char_map:
                if char_map[c] >= start:
                    start = char_map[c] + 1
                    char_map[c] = i
                    continue

            len = (i - start) + 1
            if len > longest_len:
                longest_len = len

            char_map[c] = i

        return longest_len


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

            ret = Solution().lengthOfLongestSubstring(s)

            out = str(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()