/*
 * avltree.c
 *
 *  Created on: 26-Jan-2015
 *      Author: chetan
 */

#include <stdio.h>
#include <stdlib.h>
//#include "tree.h"

// start of global var declaration

struct avltree {
	int data;
	int height;
	struct avltree *left;
	struct avltree *right;
};


// end of global var declaration

// start of function declaration
struct avltree * singleRotationLeft (struct avltree *);
struct avltree * singleRotationRight (struct avltree *);
struct avltree * doubleRotationLeft (struct avltree *);
struct avltree * doubleRotationRight (struct avltree *);
struct avltree * insertElement(struct avltree *,struct avltree *,int);
int height(struct avltree *);
int max(int,int);
void inorder(struct avltree *);
//     end of function declaration
int main () {
	int choice,ch=1,value;
	char c='y';
	struct avltree *root=NULL;
	do {
		printf("\n==========================\n         MENU         \n========================\n");
		printf("1.  insert one\n");
		printf("2.  traverse the tree\n");
		printf("Enter any other number to exit\n");
		printf("\n===========================\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			do {
				printf("Enter the value of the element: ");
				scanf("%d",&value);
				root = insertElement(root,root,value);
				printf("do you want to insert another element ? [y/n]");
				scanf("%c",&c);
				while(c == '\n')
					scanf("%c",&c);
			} while(c == 'y' || c == 'Y');
			break;
		case 2:
			printf("AVL tree : data->height\n ");
			inorder(root);
			printf("\n");
			break;
		default :
			ch = 0;
		}

	}while(ch == 1);

	return 0;
}

struct avltree * insertElement(struct avltree *root,struct avltree *parent,int data) {

	if(root == NULL) {
		root = (struct avltree *) malloc (sizeof(struct avltree));
		root->data = data;
		root->height = 1;
		root->left = root->right =NULL;
	}
	else if(root->data > data) {
		root->left = insertElement(root->left,root,data);
		if(height(root->left) - height(root->right) > 1) {
			printf("debug-1, root = %d\n",root->data);
			if(data < root->left->data)
				root = singleRotationLeft(root);
			else
				root = doubleRotationLeft(root);
		}
	}
	else if(root->data < data) {
		root->right = insertElement(root->right,root,data);
		if(height(root->left) - height(root->right) > 1) {
			printf("debug-2, root = %d\n",root->data);
			if(data < root->right->data) {
				printf("single rotation right at %d\n",root->data);
				root = singleRotationRight(root);
			}
			else {
				printf("double rotation right at %d\n",root->data);
				root = doubleRotationRight(root);
			}
		}
	}
	else
		printf("data already exists\n");
	root->height = max(height(root->left),height(root->right)) +1;
	return root;
}


struct avltree * singleRotationLeft (struct avltree *root) {

	struct avltree *temp = root->left;
	// if we will do a left rotation then temp will become root and root will become temp right child.
	// so temp's original right child has to move as temp is left ot root means temp < root so temp right
	// can moved as left child of root as root's original left becomimg new root(temp) so its left is empty
	root->left = temp->right;
	temp->right=root;
	root->height = max(height(root->left),height(root->right))+1;
	temp->height = max(height(temp->left),root->height)+1;
	return root;
}

struct avltree * singleRotationRight (struct avltree *root) {
	struct avltree *temp = root->right;
	root->right=temp->left;
	temp->left = root;
	root->height = max(height(root->left),height(root->right))+1;
	temp->height = max(root->height,height(temp->right))+1;
	return root;
}

struct avltree * doubleRotationLeft (struct avltree *root) {
	root->left = singleRotationLeft(root->left);
	return singleRotationRight(root);

}

struct avltree * doubleRotationRight (struct avltree *root) {
	root->right = singleRotationLeft(root->right);
	return singleRotationRight(root);

}


int height(struct avltree *node) {
    int left_height,right_height;
    if(node == NULL)
       return 0;
    left_height = height(node->left);
    right_height = height(node->right);
    if(left_height > right_height) {
  //  	 printf("left=%d and data=%d\n",left_height,node->data);
       return left_height+1;
    }
    else {
  //  	  printf("right=%d and data=%d\n",right_height,node->data);
        return right_height+1;
     }
}

int max(int x,int y) {

	if(x > y)
		return x;
	else
		return y;
}

void inorder(struct avltree *root) {
	if(root == NULL)
		return;
	inorder(root->left);
	printf(" %d->%d ",root->data,root->height);
	inorder(root->right);

}
