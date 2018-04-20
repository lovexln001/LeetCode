#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def longest(self, s, i, off):
        L = len(s)
        lp = i
        rp = i + off
        while(lp >=0 and rp < L and s[lp] == s[rp]):
            lp -= 1
            rp += 1
        return s[lp+1:rp]
    
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        L = len(s)
        num = [1 for i in range(L)]
        smax = ""
        for i, key in enumerate(s):
            sf = self.longest(s, i, 0)
            ss = self.longest(s, i, 1)
            if len(sf) > len(smax): smax = sf
            if len(ss) > len(smax): smax = ss
        return smax