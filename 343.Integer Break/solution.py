#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1]*(n+1)
        for i in xrange(3, n+1):
            for j in xrange(1, i):
                dp[i] = max(dp[i-j]*j, dp[i], (i-j)*j)
        return dp[n]