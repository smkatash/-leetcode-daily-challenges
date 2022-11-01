class Solution(object):
    def intersect(self, nums1, nums2):
        arr = []
        for i in nums1:
            if i in nums2:
                arr.append(i)
                nums2.remove(i)
        return arr
