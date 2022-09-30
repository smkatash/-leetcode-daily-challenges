class ListNode(object):
    def __init__(self, val=0, next=None, head=None):
         self.val = val
         self.next = None
         self.head = None
    def printList(self):
         current = self.head
         while(current):
             print(current.val, end=' ')
             current = current.next

class Solution(ListNode):
    def detectCycle(self, head):
        if head == None:
            return None
        slow = head
        fast = head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break ;
        if (fast == None or fast.next == None):
            return None
        if (slow == fast):
            slow = head;
            while (slow != fast):
                slow = slow.next
                fast = fast.next
        return slow
        


if __name__=='__main__':
    LL1 = ListNode(1)
    LL2 = ListNode(2)
    LL3 = ListNode(3)
    LL4 = ListNode(4)
    
    LL1.head = LL1
    LL1.head.next = LL2
    LL1.head.next.next = LL3
    LL1.head.next.next.next = LL4
    LL1.head.next.next.next = LL2
    Cycle = Solution(LL1).detectCycle(LL1.head)
    print(LL2)
    print(Cycle)
    
