import enum
from xml.dom.minidom import Element


class Solution(object):
    def twoSum(self, nums, target):
        arr = dict()
        for i, value in enumerate(nums):
            reminder = target - value
            if reminder in arr:
                return [arr[reminder], i]
            arr[value] = i
        return []
        