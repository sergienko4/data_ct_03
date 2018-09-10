#include "TreeNode.h"
#define _CRT_SECURE_NO_WARNINGS


TreeNode * createBST()
{
	int num = 0;
	TreeNode * tree = NULL;
	while (num != -1)
	{
		printf("\nnumber=");
		scanf_s("%d", &num);
		if (num != -1)
			tree = insertValueToBST(tree, num);
	}
	return tree;

}

TreeNode * createTreeNode(type_data data)
{
	TreeNode * temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = data;
	temp->parent = NULL;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode * insertValueToBST(TreeNode *root, type_data data)
{
	TreeNode *temp = NULL;

	if (root == NULL)
		return createTreeNode(data);


	if (data < root->data) {
		root->left = insertValueToBST(root->left, data);
		(root->left)->parent = root;
	}
	else {
		root->right = insertValueToBST(root->right, data);
		(root->right)->parent = root;
	}
	return root;
}

void printInorder(TreeNode * root)
{
	TreeNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL)
	{
		if (current->left == NULL)
		{
			printf("%d ", current->data);
			current = current->right;
		}
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Make current as right child of its inorder predecessor */
			if (pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}

			/* Revert the changes made in if part to restore - fix the right child of predecssor */
			else
			{
				pre->right = NULL;
				printf("%d ", current->data);
				current = current->right;
			} 
		} 
	}
}
void freeBST(TreeNode* root)
{
	if (root != NULL)
	{
		freeBST(root->left); freeBST(root->right);
		free(root);
	}
}



