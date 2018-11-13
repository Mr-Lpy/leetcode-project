class Solution(object):
    def isPalindrome(self, x):
        """
        :param x: int
        :return: bool
        """
        if x < 0:
            return False
        if x < 10:
            return True
        str_num = str(x)
        str_reverse = str_num[::-1]
        print(str_reverse)
        return str_reverse == str_num

    def isPalindrome2(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if x < 10:
            return True
        temp_x = x
        reverse_x = 0
        while temp_x:
            reverse_x = reverse_x * 10 + (temp_x % 10)
            temp_x = temp_x // 10       #  整除
        return reverse_x == x

s = Solution()

s.isPalindrome(222)
