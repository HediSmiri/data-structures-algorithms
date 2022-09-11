#!/usr/bin/python3

# LeetCode Problem Link : https://leetcode.com/problems/linked-list-cycle/

# LeetCode Problem : 
# Given head, the head of a linked list, determine if the linked list has a cycle in it.
# There is a cycle in a linked list if there is some node in the list that can be reached again 
# by continuously following the next pointer. 
# Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note 
# that pos is not passed as a parameter.
# Return true if there is a cycle in the linked list. Otherwise, return false.

# Definition for singly-linked list.

from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        if head is None or head.next is None:
            return False
        fast = head.next    
        slow = head
        while slow and fast and fast.next is not None:
            if slow == fast:
                return True
            slow = slow.next
            fast = fast.next.next
        return False