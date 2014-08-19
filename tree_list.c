/*************************************************************************
	> File Name: list_tree.c
	> Author: likang
	> Created Time: 2014年08月13日 星期三 12时44分31秒
 ************************************************************************/

#include<stdio.h>
#include "tree.h"
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef struct TREE_NODE
{
	TREE_TYPE value;
	struct TREE_NODE *left;
	struct TREE_NODE *right;
}TreeNode;

static TreeNode *tree;

void
insert(TREE_TYPE value)
{
	TreeNode *current;
	TreeNode **link;
	link = &tree;
	while((current = *link) != NULL){
		if(value < current->value)
			link = &current->left;
		else{
			assert(value != current->value);
			link = &current->right;
		}
	}
	current = (TreeNode *)malloc(sizeof(TreeNode));
	assert(current != NULL);
	current->value = value;
	current->left = NULL;
	current->right = NULL;
	*link = current;
}

int
find(TREE_TYPE value)
{
	TreeNode *current = tree;
	while(current != NULL && current->value != value)
	{
		if(value > current->value)
			current = current->right;
		else
			current = current->left;
	}
	if(current != NULL)
		return 1;
	return 0;
}
void
callback(TREE_TYPE value)
{
	printf("%d ",value);
}
static void
do_pre_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value))
{
	if(current != NULL)
	{
		callback(current->value);
		do_pre_order_traverse(current->left, callback);
		do_pre_order_traverse(current->right,callback);
	}
}

void
pre_order_traverse(void (*callback)(TREE_TYPE value))
{
	do_pre_order_traverse(tree, callback);
}

int
tree_depth(TreeNode *current)
{
	if(current == NULL)	
		return 0;
	int left = tree_depth(current->left);
	int right = tree_depth(current->right);
	return left > right ? left + 1 : right + 1;
}
int
main(void)
{
	int i;
	int value;
	for(i = 0; i < 10; i++)
	{
		printf("input the %d value:",i+1);
		scanf("%d",&value);
		getchar();
		insert(value);
	}
	pre_order_traverse(callback);
	int depth = tree_depth(tree);
	int left_depth = tree_depth(tree->left);
	int right_depth = tree_depth(tree->right);
	printf("\n%d\nleft:%d\nright:%d\n",depth,left_depth,right_depth);
	return 0;
}










