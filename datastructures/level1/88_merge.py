from heapq import merge
from re import M


class Solution(object):
    def merge(self, nums1, m, nums2, n):
        if len(nums2) == 0:
            return nums1
        if sum(nums1) < sum(nums2):
            for i in range(m, len(nums1)):
                nums1[i] = min(nums2)
                nums2[nums2.index(min(nums2))] = max(nums2) + 1
        else:
            for i in range(n):
                nums1[m] = nums2[i]
                m += 1
        nums1.sort()
        return nums1
        
        
def main():
    nums1 = [1,2,3,0,0,0]
    nums2 = [2,5,6]
    solution = Solution()
    print(solution.merge(nums1, 1, nums2, 1))

if __name__ == "__main__":
	main()