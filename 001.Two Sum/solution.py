#!/usr/bin/env python
# encoding: utf-8


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for index, num in enumerate(nums):
            if num in d:
                return [d[num], index]
            d[target - num] = index


if __name__ == "__main__":
    s = Solution()
    nums = [2, 7, 11, 13]
    target = 13
    assert (s.twoSum(nums, target) == [0, 2])
    nums = [3, 2, 8]
    target = 11
    assert (s.twoSum(nums, target) == [0, 2])
