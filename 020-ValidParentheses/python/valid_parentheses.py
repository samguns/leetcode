class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        symbol_stack = []

        for c in s:
            if c == '(' or c == '[' or c == '{':
                symbol_stack.append(c)
            elif c == ')' or c == ']' or c == '}':
                prev = '#'
                if len(symbol_stack) > 0:
                    prev = symbol_stack.pop()

                if prev == '#':
                    return False

                if (c == ')' and prev != '(') or\
                        (c == ']' and prev != '[') or \
                        (c == '}' and prev != '{'):
                    return False

        if len(symbol_stack) > 0:
            return False

        return True


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

            ret = Solution().isValid(s)

            out = (ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()