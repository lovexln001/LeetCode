#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur_one = cur_zero = 0
        pre_one = pre_zero = 0
        for num in nums:
            cur_zero = max(pre_one,pre_zero)
            cur_one = max(pre_zero + num, pre_zero)
            pre_zero = cur_zero
            pre_one = cur_one
        return max(cur_zero, cur_one)