#!/usr/bin/python3

# LeetCode: https://leetcode.com/problems/remove-linked-list-elements/
# We Will use DummyNode Technique To solve this Problem

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        dummyNode = prev = ListNode(0, head)
        
        while prev and prev.next:
            if prev.next.val == val: 
                prev.next = prev.next.next
            else:
                prev = prev.next

        return dummyNode.next

        
        

