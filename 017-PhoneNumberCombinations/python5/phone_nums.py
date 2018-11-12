
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        n = pow(3, len(digits))
        if n < 3:
            return []
        res = [] * n
        digit_map = {
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
            if len(res):
                loops = len(res)

            for i in range(loops):
                v = ""
                if len(res):
                    v = res.pop(0)

                for w in digit_map[d]:
                    res.append(v+w)

        return res


def stringToString(input):
    import json
    return json.loads(input)


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
            digits = stringToString(line)

            ret = Solution().letterCombinations(digits)

            out = stringArrayToString(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()