#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int count = 0;
    struct TreeNode *current = root;
    struct TreeNode *stack[1000];
    int top = -1;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        count++;
        current = current->right;
    }

    int *result = (int *)malloc(count * sizeof(int));
    if (result == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    current = root;
    top = -1;
    int index = 0;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        result[index++] = current->val;
        current = current->right;
    }

    *returnSize = count;
    return result;
}