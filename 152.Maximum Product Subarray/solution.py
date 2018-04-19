#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur_min = cur_max = 0
        pre_min = pre_max = 1
        maxval = float("-inf")
        for num in nums:
            cur_min = min(pre_min*num, pre_max*num, num)
            cur_max = max(pre_min*num, pre_max*num, num)
            pre_min = cur_min
            pre_max = cur_max
            maxval = max(maxval, cur_max)
        return maxval