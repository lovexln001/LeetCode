#!/usr/bin/env python
# encoding: utf-8



class ListNode(object):
 def __init__(self, x):
     self.val = x
     self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        r = 0
        hd = ListNode(0)
        p = None
        while(l1 != None or l2 !=None or r != 0):
            if(p == None):
                p = hd
            else:
                p.next = ListNode(0)
                p = p.next
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            m = (a + b + r) % 10
            r = (a + b + r) // 10
            p.val = m

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return hd

