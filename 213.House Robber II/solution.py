#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxsum = 0
        if len(nums) <= 3:
            return max([0]+nums)
        else:
            max_zero = {}
            max_one = {}
            for j in xrange(0,2):
                cur_one = []
                cur_zero = []
                pre_one = []
                pre_zero = []
                tnums = nums[j+1:]
                tnums.extend(nums[:j])
                for i in xrange(len(tnums)):
                    if self.get_val(pre_one, tnums) > self.get_val(pre_zero, tnums):
                        cur_zero = pre_one[:]
                    else:
                        cur_zero = pre_zero[:]

                    if self.get_val(pre_zero, tnums) + nums[i] >= self.get_val(pre_zero, tnums):
                        cur_one = pre_zero + [i]
                    else:
                        cur_one =pre_zero[:]
                    pre_one = cur_one[:]
                    pre_zero = cur_zero[:]

                maxsum = max(maxsum, self.get_val(cur_one,  tnums), self.get_val(cur_zero, tnums))
                             
            return maxsum

    def get_val(self, index, nums):
        return sum([nums[i] for i in index])