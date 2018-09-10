#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef  int type_data;
typedef struct treenode
{
	type_data data;
	struct treenode *left;
	struct treenode *right;
	struct treenode *parent;
}TreeNode;


TreeNode * createTreeNode(type_data);
TreeNode * createBST();
TreeNode * insertValueToBST(TreeNode *root, type_data data);
void printInorder(TreeNode * root);
void freeBST(TreeNode* root);
void printByLevel(TreeNode* root);
TreeNode * createBSTDDebug();

