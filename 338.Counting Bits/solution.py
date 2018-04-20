#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        dp = [0]*(num+1)
        for i in xrange(num+1):
            dp[i] = dp[i/2] if i%2 == 0 else dp[i/2]+1
        return dp