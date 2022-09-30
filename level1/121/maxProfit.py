class Solution(object):
    def maxProfit(self, prices):
        est = 0
        profit = 0
        for i in range(len(prices)):
            j = i + 1
            while j < len(prices) and prices[i] < prices[j]:
                est = prices[j] - prices[i]
                if est > profit:
                    profit = est
                j += 1
        return profit

# class Solution(object):
#     def maxProfit(self, prices):
#         profit = 0
#         for i in range(0, len(prices)):
#             for j in range (i + 1, len(prices)):
#                 profit = max(profit, prices[j] - prices[i])
#         return profit

if __name__ == "__main__":
    prices = [7,1,5,3,6,4]
    solution = Solution()
    print(solution.maxProfit(prices))
