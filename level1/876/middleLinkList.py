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
	def middleNode(self, head):
		temp = head
		count = 0
		while (temp != None):
			count += 1
			temp = temp.next
		middle = int(count / 2)
		while (middle):
			middle -= 1
			head = head.next
		return head

# if __name__=='__main__':
# 	LL1 = ListNode()
# 	LL1.insert(2)
# 	LL1.insert(4)
# 	LL1.insert(6)
# 	LL1.insert(8)
# 	print("Original List")
# 	LL1.printList()
# 	print("\nMiddle List")
# 	solution = Solution()
# 	LL2 = solution.middleNode(LL1.head)
# 	LL2.printList()
