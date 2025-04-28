
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *secondHalf = slow->next;
    struct ListNode *prev = NULL, *current = secondHalf, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    secondHalf = prev;
    struct ListNode *firstHalf = head;
    while (secondHalf != NULL)
    {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}