#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        import random
        if len(nums) >= 1:
            less = [];greater = []
            if len(nums) == 1:return nums[0]
            randnum = random.randint(0,len(nums)-1)
            pivot = nums[randnum]
            del nums[randnum]
            for num in nums:
                if num < pivot:less.append(num)
                else: greater.append(num)
            glen = len(greater)
            if glen == k-1:
                return pivot
            elif glen > k-1:
                return self.findKthLargest(greater, k)
            else:
                return self.findKthLargest(less, k-1-glen)