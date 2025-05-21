
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *merge(struct ListNode *left, struct ListNode *right)
{
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    while (left && right)
    {
        if (left->val <= right->val)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = left ? left : right;
    return dummy.next;
}
struct ListNode *findMiddle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head, *prev = NULL;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev)
    {
        prev->next = NULL;
    }
    return slow;
}
struct ListNode *sortList(struct ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    struct ListNode *mid = findMiddle(head);
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);
    return merge(left, right);
}