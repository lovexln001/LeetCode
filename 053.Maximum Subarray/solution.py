#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = g =float("-inf")
        for num in nums:
            l = max(num,l+num)
            g = max(g,l)
        return g
            