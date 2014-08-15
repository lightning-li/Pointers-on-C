/*************************************************************************
	> File Name: tree.h
	> Author: likang
	> Created Time: 2014年08月13日 星期三 12时39分01秒
 ************************************************************************/

#define TREE_TYPE int

void insert(TREE_TYPE value);

int find(TREE_TYPE value);

void pre_order_traverse(void (*callbach)(TREE_TYPE value));
