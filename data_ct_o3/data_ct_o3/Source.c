#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "TreeNode.h"

// Create by Eguene Sergienko ID 314076571 && Alex Kovalyov ID 321866477 

TreeNode *root = NULL;
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void creatTree();

void main()
{

	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 4; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-4 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select >4));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break; 
			case 3: Ex3(); break;
			case 4: Ex4(); break;

			}
		} while (all_Ex_in_loop && select);

		// if the tree isn't free from some reason then we have to free it
		freeBST(root);
		return 0;

	
}


void Ex1() {
	// create tree
	root = createBST();
	Ex2();
	Ex4();
}

void Ex2() {

	// create tree
	if (root == NULL) {
		creatTree();
	}
	// print
	printInorder(root);
	Ex4();
}

void Ex3() {
	// create tree
	if (root == NULL)
		creatTree();

	printByLevel(root);
	Ex4();

}

void Ex4() {
	
	// no tree
	if (root == NULL)
		root = createBSTDDebug();

	if (root != NULL)
		freeBST(root);

	root = NULL;
}


void creatTree() {

	printf("The tree is empty, Please fill the tree!!!");
	root = createBST();
}