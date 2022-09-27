class Solution(object):
	def isIsomorphic(self, s, t):
		return map(s.find, s) == map(t.find, t)

def main():
	s = "add"
	t = "egg"
	solution = Solution()
	print(solution.isIsomorphic(s, t))

if __name__ == "__main__":
	main()