class Solution:
    def longestCommonPrefix(self, strs):
        """

        :param strs:
        :return: str
        """
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]

        temp = strs[0]
        temp_strs = strs[1:]
        ret = ""
        for i in range(len(temp)):
            print(i)
            for j in temp_strs:
                if i > len(j)-1 or temp[i] != j[i]:
                    return ret
            ret += temp[i]
        return ret
    def longestCommonPrefix2(self, strs):
        if len(strs) == 0:
            return ""
        res = ""
        for each in zip(*strs):
            if len(set(each)) == 1:
                res += each[0]
            else:
                return res
        return res

if __name__ == '__main__':
    s = Solution()

    result = s.longestCommonPrefix2(["flower", "flow"])

    result = s.longestCommonPrefix2(["a", "aa", "aaa"])
    print(result)
