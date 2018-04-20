#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0 or s[0] == '0':return 0
        
        size = len(s)
        dp = [1]*(size+1)
        for i in xrange(2, size+1):
            num = int(s[i-2:i])
            if 10 <= num <= 26 and s[i-1] != '0':
                dp[i] = (dp[i-1] + dp[i-2])
            elif num == 10 or num == 20:
                dp[i] = dp[i-2]
            elif s[i-1] != '0':
                dp[i] = dp[i-1]
            else:
                return 0
        return dp[-1]