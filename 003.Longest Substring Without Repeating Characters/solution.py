#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        max_len ,start, end = 0, 0, 0
        while(end < length):
            subs = s[start:end]
            cur_len = end - start + 1
            if(s[end] in subs):
                start = subs.rindex(s[end]) + start + 1
                cur_len -= 1
            max_len = max(max_len, cur_len)
            end += 1
        return max_len