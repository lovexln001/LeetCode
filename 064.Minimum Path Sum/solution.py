#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        if row:
            column = len(grid[0])
        else:
            return 0
        pgrid = [[0 for i in xrange(column)] for j in xrange(row)] 
        
        if row > 0:
            pgrid[0][0] = grid[0][0]
        else:
            pgrid[0] = grid[0]          
        for j in xrange(1, row):
                pgrid[j][0] = pgrid[j-1][0] + grid[j][0]               
        for i in xrange(1, column):
                pgrid[0][i] = pgrid[0][i-1] +grid[0][i]         
            
        for j in xrange(1, row):
            for i in xrange(1, column):
                if pgrid[j-1][i] < pgrid[j][i-1]:
                    pgrid[j][i] = grid[j][i] + pgrid[j-1][i]
                else:
                    pgrid[j][i] = grid[j][i] + pgrid[j][i-1]
        
        return pgrid[row-1][column-1]