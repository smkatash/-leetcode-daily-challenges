from collections import Counter

class Solution(object):
    def findAnagrams(self, s, p):
        len_p = len(p)
        len_s = len(s)
        counter_p = Counter(p)
        counter_s = Counter(s[:len_p])
        arr = []
        if counter_p == counter_s:
            arr = [0]
        for i in range(len_p, len_s):
            remove = counter_s[s[i - len_p]]
            if remove == 1:
                del counter_s[s[i - len_p]]
            else:
                counter_s[s[i - len_p]] -= 1
            counter_s[s[i]] += 1
            if counter_s == counter_p:
                arr.append(i - len_p + 1)
        return arr
        
        
                