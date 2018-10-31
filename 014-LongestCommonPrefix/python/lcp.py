import sys


class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0 or len(strs[0]) == 0:
            return ""
        ret = ""
        min_prefix_length = sys.maxsize
        for str in strs:
            if len(str) < min_prefix_length:
                min_prefix_length = len(str)

        stop = False
        for i in range(min_prefix_length):
            common_char = strs[0][i]
            if len(common_char) == 0:
                break

            for j in range(1, len(strs)):
                if strs[j][i] != common_char:
                    stop = True

            if stop:
                break

            ret += common_char

        return ret


def main():
    import sys
    import io
    import json
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            strings = json.loads(line)

            ret = Solution().longestCommonPrefix(strings)

            out = str(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()