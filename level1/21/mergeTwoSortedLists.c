#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
 	struct ListNode *next;
};

struct ListNode*	mergeLists(struct ListNode* list1, struct ListNode* list2) {
	struct ListNode* temp = list1;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = list2;
	return (list1);
}

void	swap(int *a, int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

struct ListNode*	sortList(struct ListNode* head) {
	struct ListNode* temp;

	if (!head)
		return (NULL);
	temp = head;
	while(head->next != NULL)
	{
		if (head->val > head->next->val)
		{
			while (head->val > head->next->val){
				swap(&head->val, &head->next->val);
			}
			head = temp;
		}
		else
			head = head->next;
	}
	return (temp);
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (!list1)
		return (sortList(list2));
	else if (!list2)
		return (sortList(list1));
	else if (!list1 && !list2)
		return (NULL);
	struct ListNode* head = mergeLists(list1, list2);
	return (sortList(head));
}

int	main(void)
{
	struct ListNode *sorted;
	struct ListNode c = { 4, NULL};
	struct ListNode b = { 2, &c };
	struct ListNode a = { 1, &b };
 	struct ListNode *list1 = &a;
	struct ListNode l3 = { 4, NULL};
	struct ListNode l2 = { 3, &l3 };
	struct ListNode l1 = { 1, &l2 };
 	struct ListNode *list2 = &l1;
	sorted = mergeTwoLists(list1, list2);
	while (sorted->next != NULL)
	{
		printf("%d ", sorted->val);
		sorted = sorted->next;
	}
	return (0);
}