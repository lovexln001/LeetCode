#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        treesum = [0 for i in xrange(n+1)]
        if n <=2:
            return n
        else:
            treesum[0]=1
            treesum[1]=1
            treesum[2]=2
            for i in xrange(3, n+1):
                treesum[i] = sum([treesum[j]*treesum[i-j-1] for j in xrange(i)])
        return treesum[-1]