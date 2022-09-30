#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
 };
 
int	getListSize(struct ListNode *head)
{
	struct ListNode *temp = head;
	int				count = 0;

	while(temp)
	{
		temp = temp->next;
		count++;
	}
	return(count);
}

struct ListNode* middleNode(struct ListNode* head){
	int ListSize = getListSize(head);
	int	midPoint = ListSize / 2;
	while (midPoint)
	{
		head = head->next;
		midPoint--;
	}
	return (head);
}

int	main(void)
{
	struct ListNode *middle;
	struct ListNode *list1;
	//struct ListNode f = { 6, NULL };
	struct ListNode e = { 5, NULL };
	struct ListNode d = { 4, &e };
	struct ListNode c = { 3, &d };
	struct ListNode b = { 2, &c };
	struct ListNode a = { 1, &b };
 	list1 = &a;

	middle = middleNode(list1);
	while (middle)
	{
		printf("%d ", middle->val);
		middle = middle->next;
	}
	return (0);
}

