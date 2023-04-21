#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

#define mergeTwoLists merge_two_lists

struct ListNode *merge_two_lists(struct ListNode *a, struct ListNode *b)
{
	if (!a)
		return b;
	if (!b)
		return a;
	struct ListNode *merged = malloc(sizeof(struct ListNode));
	struct ListNode *merged_head = merged;
	struct ListNode *merged_prev;

	while (a && b)
	{
		merged_prev = merged;
		merged->val = (a->val <= b->val) * a->val + (b->val < a->val) * b->val;
		b = (b->val < a->val) ? b->next : b;
		a = (a->val == merged->val) ? a->next : a;
		
		merged->next = malloc(sizeof(struct ListNode));
		merged = merged->next;
	}

	while (a)
	{
		merged_prev = merged;
		merged->val = a->val;
		a = a->next;
		merged->next = malloc(sizeof(struct ListNode));
		merged = merged->next;
	}

	while (b)
	{
		merged_prev = merged;
		merged->val = b->val;
		b = b->next;
		merged->next = malloc(sizeof(struct ListNode));
		merged = merged->next;
	}

	free(merged);
	merged_prev->next = 0;
	return merged_head;
}
