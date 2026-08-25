# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # find mid 
        slow = head 
        fast = head 
        while fast and fast.next :
            slow = slow.next
            fast = fast.next.next 
        

        # reverse the second half 
        prev = None 
        curr = slow 
        while curr :
            next_node = curr.next
            curr.next = prev 
            prev = curr 
            curr = next_node 


        # compare fisrt half with revered second half 
        left = head 
        right = prev 

        while right :
            if left.val != right.val :
                return False
            left = left.next 
            right = right.next

        return True






        