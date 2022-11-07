import collections

class Solution:
    def characterReplacement(self, s, k):
        counts = collections.Counter()
        left, max_idx, diff = 0, 0, 0
        for right in range(len(s)):
            counts[s[right]] += 1
            max_idx = max(max_idx, counts[s[right]])
            while right - left + 1 > max_idx + k:
                 counts[s[left]] -= 1
                 left += 1
            diff = max(max_idx, right - left + 1)
        return diff