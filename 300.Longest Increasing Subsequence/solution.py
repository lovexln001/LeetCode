#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numvals = [1 for i in xrange(len(nums))]
        for i in xrange(len(nums)):
            for j in xrange(i):
                if nums[i] > nums[j]:
                    numvals[i] = max(numvals[i],numvals[j]+1)
        return max(numvals) if numvals else 0