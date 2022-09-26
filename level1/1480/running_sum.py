class Solution:
    def runningSum(self, nums):
        ans=[]
        tmp=0
        for i in nums:
            tmp+=i
            ans.append(tmp)
        return ans

def main():
	nums = [1, 2, 3, 4]
	solution = Solution()
	nums_modified = solution.runningSum(nums)
	print(nums_modified)

if __name__ == "__main__":
	main()