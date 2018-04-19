#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        dp = {-1: set()}
        for num in sorted(nums):
            dp[num] = max((dp[d] for d in dp if num%d == 0), key=len) | {num}
        return list(max(dp.values(), key=len))