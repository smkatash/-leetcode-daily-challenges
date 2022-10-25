class Solution(object):
    def backspaceCompare(self, s, t):
        str = []
        tr = []
        for i in range(len(s)):
            if s[i] == '#':
                if str:
                    str.pop()
            else:
                str.append(s[i])
        for i in range(len(t)):
            if t[i] == '#':
                if tr:
                    tr.pop()
            else:
                tr.append(t[i])
        return tr == str