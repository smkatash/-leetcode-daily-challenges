class Solution(object):
	def isSubsequence(self, s, t):
		len_s, len_t = len(s),len(t)
		i = 0
		j = 0
		while i < len_s and j < len_t:
			if s[i] == t[j]:
				i += 1
			j += 1
		return len_s == i

def main():
	s = "axc"
	t = "ahbgdc"
	solution = Solution()
	print(solution.isSubsequence(s, t))

if __name__ == "__main__":
	main()