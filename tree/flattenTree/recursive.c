/* FIXME: Implement! */

#include "BinaryTree.h"
#include <stdio.h>
#include <stddef.h>

TreeNode *flatten(TreeNode *root)
{
    if(root == NULL) {
        return NULL;
    }
    if(root->rightNode) {
        root->rightNode = flatten(root->rightNode);
    }
    if(root->leftNode) {
        TreeNode *tmp = root->rightNode;
        root->rightNode = flatten(root->leftNode);
        TreeNode *t = root->rightNode;
        while(t->rightNode) {
            t = t->rightNode;
        }
        t->rightNode = tmp;
        root->leftNode = NULL;
    }
    return root;
}

void rec_flatten(TreeNode *root)
{
    TreeNode *list = flatten(root);
    printf("Flatten Tree Recursive: ");
    while(list->rightNode) {
        printf("%d -> ",list->data);
        list = list->rightNode;
    }
    printf("NULL\n");
}
