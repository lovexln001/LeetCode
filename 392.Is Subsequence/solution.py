#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        num_s, num_t = 0, 0
        while(num_s < len(s) and num_t < len(t)):
            if s[num_s] == t[num_t]:
                num_s += 1
                num_t += 1
            else:
                num_t += 1
        return True if num_s == len(s) else False