class Solution:
    def romanToInt(self, s):
        """

        :param s: str
        :return: int
        """
        if s == "":
            return 0
        roman = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        n = len(s) - 1
        result = roman.get(s[n])

        for i in range(n-1, -1, -1):
            if s[i] not in roman.keys():
                return 0
            temp = roman.get(s[i])
            temp_last = roman.get(s[i+1])
            if temp < temp_last:
                result -= temp
                continue
            result += temp
        return result

    def romanToInt2(self, s):
        roman = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        s = s[::-1]

        num = roman[s[0]]
        last = num


        for i in s[1:]:
            if roman[i] < last:
                num -= roman[i]
            else:
                num += roman[i]
                last = roman[i]
        return num

s = Solution()

ret = s.romanToInt2("V")
print(ret)
