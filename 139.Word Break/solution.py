#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dp = [False] * len(s)
        for i in xrange(len(s)):
            for w in wordDict:
                if s[i+1-len(w):i+1] == w and (dp[i-len(w)]==True or i-len(w) == -1):
                    dp[i] = True
        return dp[-1]