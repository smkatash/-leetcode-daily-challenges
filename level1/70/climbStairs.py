class Solution(object):
    def climbStairs(self, n):
        newSum = 0
        sum = 1
        prevSum = sum
        for i in range(n):
            newSum = sum + prevSum
            prevSum = sum
            sum = newSum
        return prevSum