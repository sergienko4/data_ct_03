#include<stdio.h>
#include "TreeNode.h"

#define _CRT_SECURE_NO_WARNINGS


TreeNode *root = NULL;
void Ex1();
void Ex2();
void Ex3();
void main()
{
	//Ex1();
	//Ex2();
	Ex3();
	//freeBST(root);
}


void Ex1() {
	root = createBST();
}

void Ex2() {

	// create tree
	if (root == NULL) {
		Ex1();
	}
	// print
	printInorder(root);
}

void Ex3() {
	/*if (root == NULL)
		Ex1();*/
	root = createBSTDDebug();
	printByLevel(root);



}