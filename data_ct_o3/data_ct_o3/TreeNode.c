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
		root->left = insertValueToBST(root->left, data);
		(root->left)->parent = root;
		root->h++;
	}
	else {
		root->right = insertValueToBST(root->right, data);
		(root->right)->parent = root;
		root->h--;
	}
	

	if (root->h < 2 && root->h >-2)
		return root;
	

	// TODO :: chekc balance
	// balance left three

	if (root->h > 1) {
		temp = root->left;
		while (temp->right != NULL)
			temp = temp->right;

		temp->right = root;

		root->parent = temp;
		temp->left = root->left->left;
		root->left = NULL;

		// update h
		if (temp->left != NULL)
			temp->left->h = getH(temp->left);
		if (temp->right != NULL)
			temp->right->h = -getH(temp->right);

	}
	else if (root->h < 1) {
		int x = 10;
		// balance right three

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

	if (root == NULL)
		return 0;
	return  getH(root->left) - getH(root->right);


}

