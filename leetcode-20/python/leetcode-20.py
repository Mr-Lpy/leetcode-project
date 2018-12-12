class Solution:
    def isValid(self, s):
        """

        :param s: str
        :return:  bool
        """
        if len(s) == 0:
            return True
        if len(s) % 2 != 0:
            return False

        stack = []

        for c in list(s):
            print(c)
            if c == '(' or c == '[' or c == '{' :
                stack.append(c)
                continue
            if c == ')':
                if len(stack) == 0 or stack[len(stack) - 1] != '(':
                    return False
            if c == ']':
                if len(stack) == 0 or stack[len(stack) - 1] != '[':
                    return False
            if c == '}':
                if len(stack) == 0 or stack[len(stack) - 1] != '{':
                    return False
            stack.pop()

        return len(stack) == 0


if __name__ == '__main__':
    s = Solution()

    result = s.isValid('({})')
    print(result)

    result = s.isValid('()[]{}')
    print(result)

    result = s.isValid('(]')
    print(result)

    result = s.isValid('')
    print(result)

    result = s.isValid('(){')
    print(result)
