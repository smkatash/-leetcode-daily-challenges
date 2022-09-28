class ListNode(object):
    def __init__(self, val=0, next=None, head=None):
        self.val = val
        self.next = None
        self.head = None
    def insert(self, val):
        newNode = ListNode(val)
        if(self.head):
            current = self.head
            while(current.next):
                current = current.next
            current.next = newNode
        else:
            self.head = newNode
    def printList(self):
        current = self.head
        while(current):
            print(current.val, end=' ')
            current = current.next


class Solution(object):
    def reverseList(self, head):
        if (head == None):
            return head
            
        if (head.next == None):
            return head
            
        node = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return node

# if __name__=='__main__':
#     LL1 = ListNode()
#     LL1.insert(2)
#     LL1.insert(4)
#     LL1.insert(6)
#     LL1.insert(8)
#     print("Original List")
#     LL1.printList()
#     solution = Solution()
#     solution.reverseList(LL1)
#     print("\nReversed List")
#     LL1.printList()
 