#include <stddef.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}