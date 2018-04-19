#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        array = [[1 for j in range(n)] for i in range(m)]
        for i in xrange(1, m):
            for j in xrange(1, n):
                array[i][j] = array[i-1][j]+array[i][j-1]
        return array[m-1][n-1]
