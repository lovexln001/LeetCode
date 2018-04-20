#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        row = len(matrix)
        column = len(matrix[0]) if row else 0
        dp = [([0] * column) for i in xrange(row)]
        maxval = 0
        
        for i in xrange(row):
            dp[i][0] = int(matrix[i][0])
            maxval = max(maxval , int(dp[i][0]))
        
        for j in xrange(column):
            dp[0][j] = int(matrix[0][j])
            maxval = max(maxval , int(dp[0][j]))
            
        for i in xrange(1, row):
            for j in xrange(1, column):
                if matrix[i][j] == '1':
                    dp[i][j] = min(dp[i-1][j] ,dp[i][j-1], dp[i-1][j-1]) + 1
                    maxval = max(maxval, dp[i][j])
                else:
                    dp[i][j] = 0
                    
        return maxval * maxval