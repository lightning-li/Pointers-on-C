/*************************************************************************
	> File Name: out_tree.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年08月29日 星期五 22时45分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TN
{
    char value;
    struct TN *left;
    struct TN *right;
}TreeNode;


TreeNode *
preintoaforder(char *preorder,char *inorder, int len)
{
    if (len == 0)
    {
        return NULL;
    }
    TreeNode *tree = (TreeNode *)malloc(sizeof(TreeNode));
    tree->value = *preorder;
    int rootIndex;
    for (rootIndex = 0; rootIndex < len; rootIndex++)
    {
        if (inorder[rootIndex] == *preorder)
            break;
    }
    tree->left = preintoaforder(preorder+1,inorder,rootIndex);
    tree->right = preintoaforder(preorder+rootIndex+1,inorder+rootIndex+1,len - rootIndex -1);
    printf("%c ",tree->value);
    return tree;
}

TreeNode *
inaftopreorder(char *inorder, char *aforder, int len)
{
    if(len == 0)
        return NULL;
    TreeNode *tree = (TreeNode *)malloc(sizeof(TreeNode));
    tree->value = *(aforder+len-1);
    int rootIndex;
    printf("%c ",tree->value);
    for (rootIndex = 0; rootIndex < len; rootIndex++)
    {
        if (inorder[rootIndex] == *(aforder+len-1))
            break;
    }
    tree->left = inaftopreorder(inorder,aforder,rootIndex);
    tree->right = inaftopreorder(inorder+rootIndex+1,aforder+rootIndex,len - rootIndex -1);
    return tree;
}

int
main(void)
{
    char *inorder = "TbHVh3ogPWFLuAfGrm1xJ7we0iQYnZ8Kvqk9y5CNBD24UIcpIEMaj6SROXsdzt";
    char *aforder = "TVHo3hPgbFfAumr7Jxew1YQi0ZnGLKy9kqvNDBC54cIU28EIRS6jdsXOaMpWtz";
    inaftopreorder(inorder,aforder,strlen(inorder));
    return 0;
}
