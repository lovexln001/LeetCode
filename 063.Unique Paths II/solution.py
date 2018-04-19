#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        n = len(obstacleGrid[0]) if m else 0
        dp = [[0]*(n+1) for __ in range(m+1)]
        dp[0][1] = 1
        for j in xrange(1, m+1):
            for i in xrange(1, n+1):
                if not obstacleGrid[j-1][i-1]:
                    dp[j][i] = dp[j-1][i] + dp[j][i-1]
        return dp[m][n]