#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def __init__(self):
        self.sumlist = []
        
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        special_op = [sp for sp in special if self.filter_sp(price, sp)]
        sumval = 0
        self.shopping(price, special_op, needs, sumval)
        if self.sumlist:
            return min(self.sumlist)
        return 0
    
    def shopping(self, price, special, needs, sumval):
        for sp in special:
            if self.is_over(sp, needs):
                lastval = self.get_price(price, needs)
                self.sumlist.append(sumval+lastval)
            else:
                sub_needs = self.sub_price(sp, needs)
                sub_sumval = sumval + sp[-1]
                self.shopping(price, special, sub_needs, sub_sumval)
                
    def filter_sp(self, price, sp):
        spval = sp[-1]
        curval = 0
        for p, s in zip(price, sp):
            curval += p*s
        if spval < curval:
            return True
        else:
            False
                
    def is_over(self, sp, needs):
        for s, n in zip(sp,needs):
            if s > n:
                return True
        return False
    
    def get_price(self, price, needs):
        price_val = 0
        for i in xrange(len(price)):
            price_val += price[i]*needs[i]
        return price_val

    def sub_price(self, sp, needs):
        return [needs[i] - sp[i] for i in xrange(len(needs))]