class Solution(object):
	def search(self, nums, target):
		left = 0
		right = len(nums) - 1
		middle = 0
		while left <= right:
			middle = (left + right) // 2
			if nums[middle] < target:
				left = middle + 1
			elif nums[middle] > target:
				right = middle - 1
			else:
				return middle
		return -1


def main():
	arr = [-1,0,3,5,9,12]
	solution = Solution()
	print(solution.search(arr, 9))

if __name__ == "__main__":
	main()