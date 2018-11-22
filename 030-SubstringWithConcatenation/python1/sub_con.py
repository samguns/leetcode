import json


class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        ans = []
        n = len(s)
        cnt = len(words)
        if n <= 0 or cnt <= 0:
            return ans

        word_map = {}
        for w in words:
            if not w in word_map:
                word_map[w] = 1
            else:
                word_map[w] += 1

        word_len = len(words[0])
        if word_len > n:
            return ans

        for i in range(word_len):
            left = i
            count = 0
            str_map = {}

            for j in range(i, n-word_len+1, word_len):
                str = s[j:j+word_len]
                if str in word_map:
                    if not str in str_map:
                        str_map[str] = 1
                    else:
                        str_map[str] += 1

                    if str_map[str] <= word_map[str]:
                        count += 1
                    else:
                        while str_map[str] > word_map[str]:
                            next_str = s[left:left+word_len]
                            str_map[next_str] -= 1

                            if str_map[next_str] < word_map[next_str]:
                                count -= 1

                            left += word_len


                    if count == cnt:
                        ans.append(left)
                        str_map[s[left:left+word_len]] -= 1
                        count -= 1
                        left += word_len

                else:
                    str_map.clear()
                    count = 0
                    left = j + word_len


        return ans



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