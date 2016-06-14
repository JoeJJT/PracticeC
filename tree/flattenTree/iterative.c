/* FIXME: Implement! */
#include "BinaryTree.h"
#include <stdio.h>

TreeNode *flatten(TreeNode *root)
{
    TreeNode *tmp;
    TreeNode *head = tmp;
    while(root != NULL) {
        if(root->leftNode != NULL) {
            tmp = root->leftNode;
            while(tmp->rightNode != NULL) {
                tmp = tmp->rightNode;
            }
            tmp->rightNode = root->rightNode;
            root->rightNode = root->leftNode;
            root->leftNode = NULL;
        }
        root = root->rightNode;
    }
    return head;
}

void iter_flatten(TreeNode *root)
{
    TreeNode *list = flatten(root);
    printf("Flatten Tree Iterative:");
    while(list->rightNode) {
        printf(" %d ->",list->data);
        list = list->rightNode;
    }
    printf(" NULL\n");
}
