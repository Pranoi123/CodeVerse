#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteMiddle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }
    int count = 0;
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int mid = count / 2;
    temp = head;
    struct ListNode *prev = NULL;
    int set = 0;
    while (set < mid)
    {
        prev = temp;
        temp = temp->next;
        set++;
    }
    prev->next = temp->next;
    free(temp);

    return head;
}