#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"stack.h"

void createBst(struct tree **);
void insertElementInBst(struct tree **,int);
int main() {
	struct tree *root=NULL;
	int choice;
	char ch;
//	clrscr();
   // ask user the action plan
	do {
		printf("\n========================\n     your choice     \n========================\n");
		printf("1. create BST\n");
		printf("2. insert a element in BST\n");
		printf("3. display tree (inorder)");
		printf("\nEnter your choice? ");
		scanf("%d", &choice);
		switch(choice) {
			case 1 :
				if(root !=NULL) {
					printf("error : Tree already exists");
					r_inorder(root);
					break;
				}
				createBst(&root);
				break;
			case 2:
				if(root == NULL)
					printf("Tree not yet created. Create the tree using option 1\n");
				else {
					//insertElementInBst(root);	
				}
				break;
			case 3:
				if(root == NULL) 
					printf("BST not found\n");
				else 
					r_inorder(root);
				break;
			default:
				printf("wrong choice\n");
		}
		
		printf("do you want to continue? [y/n]");
		ch = getchar();
		while(ch == '\n')	
			ch = getchar();
	}while(ch == 'y' || ch == 'Y');

return 0;
}


void createBst(struct tree **root) {
	int val;
	char ch;	
	do {
		printf("Enter the value? :");
		scanf("%d",&val);
		insertElementInBst(root,val);
		printf("\ndo you want to inster one more element? [y/n]");
		ch = getchar();
		while(ch == '\n')	
			ch = getchar();
	}	while(ch == 'y' || ch == 'Y');
}
void insertElementInBst(struct tree **root,int val) {
		struct tree *temp = (struct tree *) malloc (sizeof(struct tree));
		struct tree *temp_root = *root;
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		if(*root == NULL)
			*root=temp;
		else {
			while(1) {
				if(temp_root->data < val) {
					if(temp_root->right == NULL) {
						temp_root->right=temp;
						break;
					}
					else 
						temp_root = temp_root->right;			
				}
				else if (temp_root->data > val) {
					if(temp_root->left == NULL) {
						temp_root->left = temp;
						break;
					}
					else 
						temp_root = temp_root->left;			
				}
				else {
					printf("data already exists can not insert duplicate value\nnode data = %d\ninseting =%d\n",temp_root->data,val);
					break;			
				}				
			}
		}
}