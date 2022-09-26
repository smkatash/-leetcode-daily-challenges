class Solution(object):
    def pivotIndex(self, nums):
        left, right = 0, sum(nums)
        for index, num in enumerate(nums):
            right -= num
            if left == right:
                return index
            left += num
        return -1

def main():
	nums = [-1,-1,-1,-1,-1,0]
	solution = Solution()
	pivotIndex = solution.pivotIndex(nums)
	print(pivotIndex)

if __name__ == "__main__":
	main()