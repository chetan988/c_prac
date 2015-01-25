#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"
#include<string.h>

struct tree*  createExprTree(char [],int);
void preorder(struct tree *);
void postorder(struct tree *);
void inorder(struct tree *);
void main() {
	char expr[30],len;
	//get the postfix expression from the console
	printf("enter postfix expression :");
	gets(expr);
	printf("the entered expression is : %s\n",expr);
	printf("\ncreating a expression tree\n");
	len = strlen(expr);
	struct tree *root = createExprTree(expr,len);
	printf("\nprinting in preorder:\n");
	preorder(root);
	printf("\nprinting in postorder:\n");
	postorder(root);
	printf("\nprinting in  inorder:\n");
	inorder(root);
	printf("\n");
}

struct tree * createExprTree(char expr[],int len) {
	int i;
	struct stack *s = createStack(len);
	struct tree *temp,*t2,*t1;
	for(i=0;i<len;i++) {
		temp=(struct tree *) malloc(sizeof(struct tree));
		temp->data = expr[i];
		if((expr[i] > 64 && expr[i] < 91) || (expr[i] > 96 && expr[i] <123)) {
			// it is just a operand so push it
			temp->left=NULL;
			temp->right=NULL;
		}
		if(expr[i] == '*' || expr[i] == '+' || expr[i] == '-' || expr[i] == '/' ) {
				t2=pop(s);			// get second operand
				t1=pop(s);			// get first operand
				temp->left=t1;		//put first in left
				temp->right=t2;	// put second in right
		}
		push(s,temp);
	}
	return temp;
}

void preorder(struct tree *root) {
	if(root == NULL)
		return;
	 printf("%c ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct tree *root) {
	if(root == NULL)
		return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}
void inorder(struct tree *root) {
	if(root == NULL)
       return;
    inorder(root->left);
    printf("%c ",root->data);
    inorder(root->right);
}