import json


class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        n = len(digits)
        res = []
        if n == 0:
            return res

        digit_code = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }

        for d in digits:
            loops = 1
            if len(res) > 0:
                loops = len(res)

            codes = digit_code[d]
            for i in range(loops):
                v = ''
                if len(res) > 0:
                    v = res.pop(0)

                for w in codes:
                    res.append(v+w)

        return res


def stringToString(input):
    return json.loads(input)


def stringArrayToString(input):
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
            digits = stringToString(line)

            ret = Solution().letterCombinations(digits)

            out = stringArrayToString(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()