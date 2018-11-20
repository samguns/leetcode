class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == -2147483648 and divisor == -1:
            return 2147483647

        sign = 1
        if (dividend < 0 and divisor > 0) or \
            (dividend > 0 and divisor < 0):
            sign = -1

        if dividend < 0:
            dividend = -dividend
        if divisor < 0:
            divisor = -divisor

        if divisor > dividend:
            return 0
        if divisor == dividend:
            return sign

        n_bits = 0
        n = dividend
        while n != 0:
            n_bits += 1
            n >>= 1

        Q = 0
        R = 0
        for i in range(n_bits-1, -1, -1):
            R <<= 1
            n_i = dividend & (1 << i)
            R |= (n_i >> i)
            if R >= divisor:
                R -= divisor
                Q |= 1 << i

        if sign == -1:
            return -Q

        return Q


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
            dividend = int(line);
            line = next(lines)
            divisor = int(line);

            ret = Solution().divide(dividend, divisor)

            out = str(ret);
            print(out)
        except StopIteration:
            break


if __name__ == '__main__':
    main()