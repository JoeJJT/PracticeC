#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stddef.h>
#include "../lib/BinaryTree.h"

extern void rec_flatten(TreeNode *root);
extern void iter_flatten(TreeNode *root);

static double diff_in_second(struct timespec t1,struct timespec t2)
{
    struct timespec diff;
    if(t2.tv_nsec - t1.tv_sec < 0) {
        diff.tv_sec = t2.tv_sec -t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

TreeNode *InsertLeftNode(int data,TreeNode *e)
{
    e->leftNode = (TreeNode *)malloc(sizeof(TreeNode));
    e = e->leftNode;
    e->data = data;
    e->leftNode = NULL;
    e->rightNode = NULL;
    return e;
}

TreeNode *InsertRightNode(int data,TreeNode *e)
{
    e->rightNode = (TreeNode *)malloc(sizeof(TreeNode));
    e = e->rightNode;
    e->data = data;
    e->leftNode = NULL;
    e->rightNode = NULL;
    return e;
}

TreeNode *CreateTestCase()
{
    /*Create test case
    *			1
    *	   	   / \
    *		  2   5
    *		 / \   \
    *       3   4   6
    */
    int testdata[6] = {1,2,3,4,5,6};
    TreeNode *node_1 = (TreeNode *)malloc(sizeof(TreeNode));
    node_1->data = testdata[0];
    node_1->leftNode = (TreeNode *)malloc(sizeof(TreeNode));
    node_1->rightNode = (TreeNode *)malloc(sizeof(TreeNode));

    TreeNode *node_2 = node_1->leftNode;
    node_2->data = testdata[1];
    node_2->leftNode = (TreeNode *)malloc(sizeof(TreeNode));
    node_2->rightNode = (TreeNode *)malloc(sizeof(TreeNode));

    TreeNode *node_3 = node_2->leftNode;
    node_3->data = testdata[2];
    node_3->leftNode = NULL;
    node_3->rightNode = NULL;

    TreeNode *node_4 = node_2->rightNode;
    node_4->data = testdata[3];
    node_4->leftNode = NULL;
    node_4->rightNode = NULL;

    TreeNode *node_5 = node_1->rightNode;
    node_5->data = testdata[4];
    node_5->leftNode = NULL;
    node_5->rightNode = (TreeNode *)malloc(sizeof(TreeNode));

    TreeNode *node_6 = node_5->rightNode;
    node_6->data = testdata[5];
    node_6->rightNode = NULL;
    node_6->leftNode = NULL;

    return node_1;
}

int main()
{
#if defined(REC)
    double cpu_time_rec;
#endif
#if defined(ITER)
    double cpu_time_iter;
#endif
    struct timespec start ,end;
    FILE *fp = fopen("result.txt","a");

    TreeNode *root = CreateTestCase();
    assert( (root != NULL) && "root should not be NULL!\n");


    /*flatten tree
    *	1
    *	 \
    *	  2
    *	   \
    *		3
    *		 \
    *		  4
    *		   \
    *			5
    *			 \
    *			  6
    */
#if defined(REC)
    clock_gettime(CLOCK_REALTIME,&start);
    rec_flatten(root);
    clock_gettime(CLOCK_REALTIME,&end);
#endif
#if defined(ITER)
    clock_gettime(CLOCK_REALTIME,&start);
    iter_flatten(root);
    clock_gettime(CLOCK_REALTIME,&end);
#endif

    void FreeTestCase(TreeNode *root) {
        if(root == NULL) {
            return;
        }

        FreeTestCase(root->leftNode);
        FreeTestCase(root->rightNode);

        free(root);
    }
#if defined(REC)
    cpu_time_rec = diff_in_second(start,end);
    printf("%1f sec\n",cpu_time_rec);
#endif
#if defined(ITER)
    cpu_time_iter = diff_in_second(start,end);
    printf("%1f sec\n",cpu_time_iter);
#endif
    free(root);
    fclose(fp);
    return 0;
}
