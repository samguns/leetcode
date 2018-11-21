import json


class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        n = len(words)
        self.substrs_hashmap = {}
        self.generate_permutations(words, n, n)

        m = 0
        if n > 0:
            m = len(words[0]) * n
        res = []
        hashmap_2 = {}
        for str in self.substrs_hashmap:
            for i in range(len(s) - m + 1):
                idx = s[i:].find(str)
                if idx != -1:
                    if (idx+i) in hashmap_2:
                        continue
                    res.append(idx+i)
                    hashmap_2[idx+i] = idx+i

        return res


    def generate_permutations(self, words, size, n):
        if size == 1:
            substr = ""
            for i in range(n):
                substr += words[i]

            self.substrs_hashmap[substr] = substr
            return

        for j in range(size):
            self.generate_permutations(words, size-1, n)

            # If size is odd, swap first and last element
            if size % 2 == 1:
                words[0], words[size-1] = words[size-1], words[0]
            # If size is even, swap jth and last element
            else:
                words[j], words[size-1] = words[size-1], words[j]

        return


def stringToString(input):
    return json.loads(input)


def stringToStringArray(input):
    return json.loads(input)


def integerListToString(nums, len_of_list=None):
    if not len_of_list:
        len_of_list = len(nums)
    return json.dumps(nums[:len_of_list])


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
            words = stringToStringArray(line)

            ret = Solution().findSubstring(s, words)

            out = integerListToString(ret)
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()