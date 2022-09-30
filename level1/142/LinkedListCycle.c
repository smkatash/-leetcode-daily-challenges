#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if (!head)
        return (NULL);
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (!fast || !fast->next)
        return (NULL);
    if (slow == fast)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return (slow);
}

int	main(void)
{
	struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *cyclePosition;
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = head->next;
	cyclePosition = detectCycle(head);
	printf("Verify: cycle position at %p and actual position at %p\n", cyclePosition, head->next);
	printf("Value: %d ", cyclePosition->val);
	return (0);
}
