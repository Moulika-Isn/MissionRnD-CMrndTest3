/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};

/*void bst_to_dll(struct node* bst, struct node **last, struct node **dll)
{ // CONVERTING BINARY SEARCH TREE TO DOUBLE LINKED LIST
	if (!bst)
		return;
	bst_to_dll(bst->left, last, dll);
	if (*last)
		(*last)->right = bst;
	else
		*dll = bst;
	bst->left = *last;
	*last = bst;
	if (bst->right)
		bst_to_dll(bst->right, last, dll);
	return;
}
int areEqual(struct node_dll *head, struct node *dll)
{ // CHECKING IF BOTH THE LINKED LISTS ARE SAME
	while (!head && !dll)
	{
		if (head->data == dll->data)
		{
			head = head->next;
			dll = dll->right;
		}
		else
			return 0;
	}
	return 1;
}*/
/*
int inorder(struct node *root,struct node_dll *head)
{
	if (root != NULL && head!=NULL)
	{
		inorder(root->left,head);
		if (head->data == root->data)
		{
			inorder(root->right, head->next);
		}
		else
			return 0;
	}
	if (root == NULL && head == NULL)
		return 1;
}
int preorder(struct node*root, struct node_dll *head)
{
	if (root != NULL && head != NULL)
	{
		if (head->data == root->data)
		{
			preorder(root->left, head->next);
			preorder(root->right, head->next);
		}
		else
			return 0;
	}
	if (root == NULL && head == NULL)
		return 1;
}
int postorder(struct node*root, struct node_dll *head)
{
	if (root != NULL && head != NULL)
	{
		postorder(root->left, head);
		postorder(root->right, head);
		if (head->data == root->data)
			head = head->next;
		else
			return 0;
	}
	if (root == NULL && head == NULL)
		return 1;
}*/
int bst(struct node *root, int *prod)
{
	int len = 0;
	if (root != NULL)
	{
		bst(root->left, prod);
		*prod = *prod * root->data;
		len++;
		bst(root->right, prod);
	}
	return len;
}
int dll(struct node_dll *head, int *prod)
{
	int len = 0;
	while (head != NULL)
	{
		*prod = *prod * head->data;
		head = head->next;
		len++;
	}
	return len;
}
int is_identical(struct node_dll *head, struct node *root){
	if(head==NULL || root==NULL)
		return -1;
	/*struct node *dll, *last;
	dll = last = NULL;
	bst_to_dll(root, &last, &dll);
	if (areEqual(head, dll))
		return 1;
	else
		return 0;
		*/
	//return (inorder(root, head)|| preorder(root,head)||postorder(root,head));
	int len_bst = 0, len_dll = 0;
	int prod_bst = 1, prod_dll = 1;
	len_bst = bst(root, &prod_bst);
	len_dll = dll(head, &prod_dll);
	if (len_dll == len_bst)
	{
		if (prod_bst == prod_dll)
			return 1;
	}
	else
		return 0;
}