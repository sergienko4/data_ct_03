#include<stdio.h>
#include "TreeNode.h"
#define _CRT_SECURE_NO_WARNINGS
void main()
{
	TreeNode *root = NULL;
	root = createBST();
	printInorder(root);
	//freeBST(root);
}