#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        symbols = [nums[i-1]-nums[i] for i in xrange(1,len(nums))]
        nes = -1
        pos = 1
        nes_num = 1
        pos_num = 1
        for sym in symbols:
            if pos * sym < 0:
                pos_num += 1
                pos = sym
            if nes * sym < 0:
                nes_num += 1
                nes = sym
        return max(nes_num, pos_num) if nums else 0