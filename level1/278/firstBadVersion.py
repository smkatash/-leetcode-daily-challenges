class Solution(object):
    def firstBadVersion(self, n):
		left = 1
		right = n
		while left <= right:
			middle = (left + right) // 2
			if isBadVersion(middle):
				if not isBadVersion(middle-1):
					return middle
				right = middle - 1
			else:
				left = middle + 1
		return 0