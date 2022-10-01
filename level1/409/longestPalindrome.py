import collections

class Solution:
    def longestPalindrome(self, s):
        d = collections.Counter(s)
        ans = 0
        odd = 0
        for key in d:
            if d[key] % 2 == 0:
                ans += d[key]
            else:
                ans += d[key] - 1
                odd = 1
        ans += odd
        return ans