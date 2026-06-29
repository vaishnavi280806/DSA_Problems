class Solution(object):
    def numOfStrings(self, patterns, word):
        res = 0
        for pt in patterns:
            if pt in word:
                res += 1
        return res
        