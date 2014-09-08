/*************************************************************************
	> File Name: RB_tree.c
	> Author:likang 
	> Mail: 
	> Created Time: 2014年09月08日 星期一 10时30分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct RB
{
    int value;            //value of Node
    char color;           //'r' stands for color "red", 'b' stands for color "black"
    struct RB *left;
    struct RB *right;
    struct RB *parent;
}RBNode;

static RBNode *root = NULL;

void RB_insert(int value);
void RB_insert_fix(RBNode *current);
void RB_left_rotate(RBNode *current);
void RB_right_rotate(RBNode *current);
void preorder(RBNode *T);



void
RB_insert(int value)
{
    RBNode *current;
    RBNode **link;
    RBNode *previous;
    link = &root;
    previous = NULL;
    while((current = *link) != NULL)
    {
        previous = current;
        if (current->value <= value)
            link = &current->right;
        else
            link = &current->left;
    }
    current = (RBNode *)malloc(sizeof(RBNode));
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    current->color = 'r';
    current->parent = previous;
    *link = current;
    printf("修复前:");
    preorder(root);
    printf("修复后:");
    RB_insert_fix(current);
    preorder(root);
}

/*
 * 如果插入的结点的父结点是黑色的话，什么都不需要做
 * 插入修复情况1：如果插入的结点是根节点的话，那么只需要将根节点涂为黑色即可
 * 插入修复情况2：如果当前结点的父结点是红色且组父结点的另一个子结点（叔叔结点）是红色
 * 插入修复情况3：如果当前结点的父结点是红色，叔叔结点是黑色，当前结点是其父结点的右子
 * 插入修复情况4：如果当前结点的父结点是红色，叔叔结点是黑色，当前结点是其父结点的左子
 */

void
RB_insert_fix(RBNode *current)
{
    RBNode *parent, *gparent, *uncle, *temp;
    if (current->parent == NULL)           //case 1
    {
        root->color = 'b';
        return;
    }
    if (current->parent->color == 'b')
        return;
    while ((parent = current->parent) && parent->color == 'r')
    {
        gparent = parent->parent;
        if (gparent->left == parent)                    //当父亲为祖父的左孩子时
        {
            uncle = gparent->right;
            if (uncle && uncle->color == 'r')           //case 2:将父亲/叔叔涂为黑色，祖父涂为红色，然后将当前结点指向祖父结点，重新开始
            {
                gparent->color = 'r';
                parent->color = 'b';
                uncle->color = 'b';
                current = gparent;
            }
            else
            {
                if (parent->right == current)           //当前结点是父亲结点的右孩子时
                {
                    current = parent;                   //当前结点指向父结点
                    RB_left_rotate(current);            //左旋
                }
                current->parent->color = 'b';           //当前结点的父结点变为黑色
                current->parent->parent->color = 'r';   //当前结点的祖父结点变为红色
                RB_right_rotate(current->parent->parent);//当前结点的祖父结点为支点右旋
            }
        }
        else                                            //当父亲为祖父的右孩子时
        {
            uncle = gparent->left;
            if (uncle && uncle->color == 'r')           //case 2:同上
            {
                uncle->color = 'b';
                parent->color = 'b';
                gparent->color = 'r';
                current = gparent;
            }
            else
            {
                if (parent->left == current)            //当前结点是其父结点的左子
                {
                    current = parent;
                    RB_right_rotate(current);           //以当前结点右旋
                }
                current->parent->color = 'b';
                current->parent->parent->color = 'r';
                RB_left_rotate(current->parent->parent);//以当前结点的祖父结点左旋
            }
        }
    }
    root->color = 'b';
}

/*
 *树的左旋

 node            r
 /  \           /  \
 a   r     ==> node c  
    / \        /  \
    b  c       a   b
 */

void
RB_left_rotate(RBNode *current)
{
    RBNode *temp = current->right;
    if ((current->right = temp->left))
    {
        current->right->parent = current;
    }
    temp->left = current;

    if ((temp->parent = current->parent))
    {
        if (current == current->parent->left)
            temp->parent->left = temp;
        else
            temp->parent->right = temp;
    }
    else
    {
        root = temp;
    }
    current->parent = temp;

}

/*
 * 树的右旋
 *    node               l
 *    /  \              / \
 *   l    y      ==>   a   node
 *  / \                    /  \
 *  a  b                   b   y
 */

void
RB_right_rotate(RBNode *current)
{
    RBNode *temp = current->left;
    if ((current->left = temp->right))
    {
        current->left->parent = current;
    }
    temp->right = current;
    if ((temp->parent = current->parent))
    {
        if (current == current->parent->left)
            current->parent->left = temp;
        else
            current->parent->right = temp;

    }
    else
    {
        root = temp;
    }
    current->parent = temp;
}

void
preorder(RBNode *T)
{
    if (T == NULL)
        return;
    printf("%d : %c\n",T->value,T->color);
    preorder(T->left);
    preorder(T->right);
}



int
main(void)
{
    int i;
    int value;
    for (i = 0; i < 6; i++)
    {
        scanf("%d",&value);
        RB_insert(value);
    }
    return 0;
}
