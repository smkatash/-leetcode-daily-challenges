#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
 	struct ListNode *next;
};

struct ListNode* getNewHead(struct ListNode* head) {
	struct ListNode* temp = head;
	if (!head)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void getTail(struct ListNode* tempHead, struct ListNode* head) {
	if (!tempHead || !head)
		return ;
	struct ListNode* temp = head;
	if (temp == tempHead) {
		tempHead->next = temp;
		temp->next = NULL;
		return ;
	}
	while (temp->next != tempHead)
		temp = temp->next;
	tempHead->next = temp;
	getTail(temp, head);
}

struct ListNode* reverseList(struct ListNode* head){
	if (!head)
		return (NULL);
	struct ListNode* temp = head;
	struct ListNode* newHead = getNewHead(head);
	struct ListNode* tempHead = newHead;
    getTail(tempHead, head);
	return (newHead);
}

// int	main(void)
// {
// 	struct ListNode *reversed;
// 	struct ListNode *list1;
// 	struct ListNode d = { 1, NULL };
// 	struct ListNode c = { 2, &d };
// 	struct ListNode b = { 1, &c };
// 	struct ListNode a = { 1, &b };
//  	list1 = &a;

// 	reversed = reverseList(list1);
// 	while (reversed)
// 	{
// 		printf("%d ", reversed->val);
// 		reversed = reversed->next;
// 	}
// 	return (0);
// }