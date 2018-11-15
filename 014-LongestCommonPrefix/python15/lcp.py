import sys

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0 or len(strs[0]) == 0:
            return ""
        min_length = sys.maxsize
        for str in strs:
            length = len(str)
            if length < min_length:
                min_length = length

        ret = ""
        for i in range(min_length):
            for c in strs[0][i]:
                for j in range(1, len(strs)):
                    if c != strs[j][i]:
                        return ret

                ret += c

        return ret


def stringToStringArray(input):
    import json
    return json.loads(input)


def main():
    import io
    import sys
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            strs = stringToStringArray(line)

            ret = Solution().longestCommonPrefix(strs)

            print(ret)
        except StopIteration:
            break


if __name__ == '__main__':
    main()