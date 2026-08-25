# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0)

        dummy.next = head

        prev = dummy 

        for _ in range(left - 1 ):
            prev = prev.next

        curr = prev.next

        for _ in range(right - left):
            temp = curr.next 

            curr.next = temp.next 


            temp.next = prev.next 
            prev.next = temp

        return dummy.next



# This is a very good linked-list problem because it combines traversing to a position with reversing pointers.

# We'll solve it step by step, using O(1) extra space and one pass through the list.