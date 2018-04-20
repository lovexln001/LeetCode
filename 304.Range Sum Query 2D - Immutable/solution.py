#!/usr/bin/env python
# encoding: utf-8


class NumMatrix(object):

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        import copy
        row = len(matrix)
        col = len(matrix[0]) if row else 0
        dp = copy.deepcopy(matrix)
        for i in xrange(1,row):
            dp[i][0] = dp[i-1][0] + matrix[i][0]
        for j in xrange(1,col):
            dp[0][j] = dp[0][j-1] + matrix[0][j]
        for i in xrange(1, row):
            for j in xrange(1, col):
                dp[i][j]=matrix[i][j]-dp[i-1][j-1]+dp[i-1][j]+dp[i][j-1]
        self.matrix = matrix
        self.dp = dp
        

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        a = self.dp[row1-1][col1-1] if row1-1 >= 0 and col1-1 >= 0 else 0
        b = self.dp[row2][col1-1] if col1-1 >= 0 else 0
        c = self.dp[row1-1][col2] if row1-1 >= 0 else 0
        d = self.dp[row2][col2]
        if row2-row1 ==0 and col2-col1==0:
            return self.matrix[row1][col1] if len(self.matrix[0]) else self.matrix[col1]
        else:
            return d + a - b - c


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)