#include "TreeNode.h"
#define _CRT_SECURE_NO_WARNINGS


TreeNode * createBST()
{
	int num;
	TreeNode * tree = NULL;
	printf("\nnumber=");
	scanf_s("%d", &num);
	while (num != -1)
	{
		tree = insertValueToBST(tree, num);
		printf("\nnumber=");
		scanf_s("%d", &num);
	}
	return tree;

}

TreeNode * createTreeNode(type_data data)
{
	TreeNode * temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = data;
	temp->h = 0;
	temp->parent = NULL;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode * insertValueToBST(TreeNode *root, type_data data)
{
	TreeNode *temp = NULL;

	int right = 0, left = 0;
	if (root == NULL)
		return createTreeNode(data);


	if (data < root->data) {
		root->h++;
		root->left = insertValueToBST(root->left, data);
		(root->left)->parent = root;

	}
	else {
		root->h--;
		root->right = insertValueToBST(root->right, data);
		(root->right)->parent = root;

	}

	root->h = getH(root);

	if (root->h < 2 && root->h >-2)
		return root;


	// TODO :: chekc balance
	// balance left three

	if (root->h > 1) {
		temp = root->left;
		while (temp->right != NULL)
			temp = temp->right;
		temp->right = root;
		temp->parent = root->parent;
		root->parent = temp;
		temp->left = root->left->left;
		root->left = NULL;



	}
	else if (root->h < 1) {
		temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;
		temp->left = root;
		temp->parent = root->parent;
		root->parent = temp;
		temp->right = root->right->right;
		root->right = NULL;
	}
	// update h
	temp->h = 0;
	if (temp->left != NULL) {
		temp->left->h = getH(temp->left);
		temp->h = temp->left->h;
	}
	if (temp->right != NULL) {
		temp->right->h = getH(temp->right);
		temp->h -= temp->right->h;
	}


	//temp->h = getH(temp);
	return temp;
}

void printInorder(TreeNode * root)
{
	if (root == NULL)
		return;
	printInorder(root->left);
	printf("%d\t", root->data);
	printInorder(root->right);
}
void freeBST(TreeNode* root)
{
	if (root != NULL)
	{
		freeBST(root->left); freeBST(root->right);
		free(root);
	}
}

int getH(TreeNode *root) {
	int right = 0, left = 0, result = 0;
	TreeNode *temp = root;
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return 0;

	left = getH(root->left);
	right = getH(root->right);
	result = (left - right);
	/*if (root == NULL)
		return 0;*/
	return result;


}

