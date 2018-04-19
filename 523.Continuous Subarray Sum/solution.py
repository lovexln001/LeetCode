#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dp = [0]
        cur_sum = 0
        if len(nums) < 2:return False
        if k == 0:
            for i in xrange(1, len(nums)):
                if nums[i] == 0 and nums[i-1] == 0:
                    return True
        else:
            for i in xrange(len(nums)):
                cur_sum += nums[i]
                cur_sum %= k
                if cur_sum in dp and len(dp) > 1:
                    return True
                else:
                    dp.append(cur_sum)
        return False