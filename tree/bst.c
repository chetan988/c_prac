#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"stack.h"

//		function declaration
void createBst(struct tree **);
void insertElementInBst(struct tree **,int);
int getMinBST(struct tree *);
int getMaxBST(struct tree *);
int findElementInBST(struct tree *,int);
struct tree * insertNewElement_Rec(struct tree *,int);
struct tree * deleteElement_Rec(struct tree *,int);
int checkifBST(struct tree *,int,int);

void createDLL(struct tree *,struct tree **,struct tree **);
void traverseDLL(struct tree *);
void traverseSLLReverse(struct tree *);
struct tree *DLLToTree(struct tree *);
struct tree *findMidOfDll(struct tree *);

struct tree * findkthsmallele(struct tree *,int);
void printRange_1 (struct tree *,int,int);

// 		end function declaration

// global variable

int count;

//

int main() {
	struct tree *root=NULL,*binary_tree_root=NULL,*dll_tail=NULL;
	struct tree *dll_head = NULL,*temp;
	int choice,i,min,max,status,element,val;
	char ch='y';
	int arr[11] = {40,5,20,30,25,50,10,1,45,60,41};
//	clrscr();
   // ask user the action plan
	do {
		printf("\n========================\n     your choice     \n========================\n");
		printf("1.  create BST\n");
		printf("2.  insert a element in BST\n");
		printf("3.  display tree \n");
		printf("4.  create a binary tree with data: 40,5,20,30,25,50,10,1,45,60,41\n");
		printf("5.  get minimum element in the tree\n");
		printf("6.  get maximum element in the tree\n");
		printf("7.  Find a element\n");
		printf("8.  Insert an element (recursive api)\n");
		printf("9.  Delete an element (recursive api)\n");
		printf("10. check if the tree is bst\n");
		printf("11. transfer binary tree to double linklist\n");
		printf("12. transfer a DLL to tree\n");
		printf("13. find the kth element\n");
		printf("14. print all emement between range k1 and k2\n");
		printf("Enter any key other than choice to exit\n");
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
					printf("Enter the element: ");
					scanf("%d",&val);
					insertElementInBst(&root,val);
				}
				break;
			case 3:
				if(root == NULL) 
					printf("BST not found\n");
				else {
					printf("\nBST in inorder\n ");
					r_inorder(root);
					printf("\nBST in preorder\n ");
					r_preorder(root);
					printf("\nBST in postorder\n ");
					r_postorder(root);
				}
				break;
			case 4:
				for(i=0;i<11;i++)
					insertElementInBst(&root,arr[i]);
				break;
			case 5:
				min= getMinBST(root);
				printf("Minimum element in the BST : %d",min);
				printf("\n");
				break;

			case 6:
				max = getMaxBST(root);
				printf("Maximum element in the BST : %d",max);
				printf("\n");
				break;
			case 7:
				printf("Enter the element to search: ");
				scanf("%d",&element);
				status = findElementInBST(root,element);
				if(status)
					printf("element %d found ...\n",element);
				else
					printf("element %d not found...\n",element);
				break;
			case 8:
				printf("enter the element: ");
				scanf("%d",&val);
				root = insertNewElement_Rec(root,val);
				break;
			case 9 :
				printf("enter the element: ");
				scanf("%d",&val);
				root = deleteElement_Rec(root,val);
				break;
			case 10:
				printf("creating the default BST tree and a normal binary tree with same data\n");
				for(i=0;i<11;i++)
					insertElementInBst(&root,arr[i]);
				binary_tree_root = createTreeFromArrayMid(arr,0,10);
				printf("tree 1 : ");
				r_inorder(root);
				printf("\ntree 2 : ");
				r_inorder(binary_tree_root);
				printf("\n");
				if(isBST_3(root))
					printf("Tree 1 is BST\n");
				else
					printf("Tree 1 is not BST\n");
				if(isBST_3(binary_tree_root))
					printf("Tree 2 is BST\n");
				else
					printf("Tree 2 is not BST\n");
				break;
			case 11:
			       //printf("[main]root=%d\n",root->data);
			       createDLL(root,&dll_head,&dll_tail);
			       printf("creating Double link list from the tree\ntraversing from head to tail\n");
			       traverseDLL(dll_head);
			       printf("printing DLL in reverse order\n");
			       traverseSLLReverse(dll_tail);
			       break;
			case 12:
				root = DLLToTree(dll_head);
				struct tree *t=root;
				while(t != NULL) {
				printf("data = %d\n",t->data);
				t=t->left;
				}
				break;
			case 13:
				printf("enter the kth value: ");
				scanf("%d",&val);
				count=0;
				temp = findkthsmallele(root,val);
				if(temp)
					printf("kth smallest element is : %d",temp->data);	
				else
					printf("element not found\n");			
				break;
			case 14:
				printf("enter the value of k1 and k2\n");
				scanf("%d %d",&min,&max);
				printRange_1 (root,min,max);
				break;
			default:
				printf("Exiting....\n");
				ch='n';
				break;
		}
//		printf("ch = %c\n",ch);
	}while(ch == 'y' || ch == 'Y');

return 0;
}
//		******** END OF MAIN **************


// 		***********  START OF FUNCTION BODY  ***************

void createBst(struct tree **root) {
	int val;
	char ch;	
	do {
		printf("Enter the value? :");
		scanf("%d",&val);
		insertElementInBst(root,val);
		printf("\ndo you want to insert one more element? [y/n]");
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

int getMaxBST( struct tree *root) {
	if(root->right == NULL)
		return (root->data);
	else
		getMaxBST(root->right);
}

int getMinBST (struct tree *root) {
	if(root->left == NULL)
		return (root->data);
	else
		getMinBST(root->left);
}

int findElementInBST(struct tree *root,int val){
	if(root == NULL)
		return 0;
	if(root->data == val)
		return 1;
	else if(root->data > val)
		return findElementInBST(root->left,val);
	else
		return findElementInBST(root->right,val);
}


struct tree * insertNewElement_Rec(struct tree *root,int data) {
	if(root == NULL) {
		// this is the place to insert the new node
		// because in BST new element is always a leaf
		struct tree *temp = (struct tree *) malloc (sizeof(struct tree));
		temp->data = data;
		temp->right = temp->left = NULL;
		root = temp;
		return root;
	}

	else if(root->data > data)
		root->left = insertNewElement_Rec(root->left,data);

	else if(root->data < data)
		root->right = insertNewElement_Rec(root->right,data);

		return root;
}


struct tree * deleteElement_Rec(struct tree *root,int data) {

	if(root == NULL)
		printf("data not found\n");
	else if(root->data > data)
		root->left = deleteElement_Rec(root->left,data);
	else if (root->data < data)
		root->right = deleteElement_Rec(root->right,data);
	else {
		struct tree *temp;
		// data found delete it
		if(root->right != NULL && root->left != NULL) {
			// both child exist so get the left max element so left to that element will all small
			// and right to it will be all large(we can get smallest on right also)
			temp = root->left;
			while(temp->right != NULL)
				temp = temp->right;
			root->data = temp->data;	// override the data
			root->left = deleteElement_Rec(root->left,temp->data);
		}
		else if(root->left != NULL || root->right != NULL) {
			// any one child exist so delete that node
			if(root->right != NULL) {
				temp= root;
				root= root->right;
				free(temp);
			}
			else {
				temp = root;
				root = root->left;
				free(temp);
			}
		}
		else {
			// node is a leaf node so make the node return NULL
			temp = root;
			root=NULL;
			free(temp);
		}
	}
	return root;
}
// this method is not 
int isBST(struct tree *root) {
	if(root == NULL)
		return 1;
	// if root->data < root->left->data then not a bst
	if((root->left != NULL ) && (root->data < root->left->data))
		return 0;
	if((root->right != NULL) && (root->data > root->right->data))
		return 0;
	// now traverse through tree when not BST return 0 from there else if root is null then at leaf node  return 1
	if( !isBST(root->left) || !isBST(root->right))
		return 0;
	// if comming here till now the tree is BST
	return 1;

}

// inorder traversal of BST result a sorted list so store the prev element and next element should be less than prev
int isBST_1(struct tree *root) {
	static int min = 0;  // an acceptable minimum value
	if(root == NULL)
		return 1;
	if( !isBST_1(root->left))
		return 0;
	if(root->data < min)
		return 0;
	min = root->data;
	return isBST_1(root->right);	
}

// this is same as isBST_1 but with a static tree 

int isBST_2(struct tree * root) {
	static struct tree *prev = NULL;	
	
	if(root == NULL)
		return 1;
	if(!isBST(root->left))
		return 0;
	if(prev != NULL && root->data < prev->data)
		return  0;
	prev = root;
	return isBST_2(root->right);			

}
// this another method , this will produce accurate result but has high time complexcity
int isBST_3(struct tree *root) {
	return checkifBST(root,0,100);

}
int checkifBST(struct tree *root,int min,int max) {
	if(root == NULL)
		return 1;
//	printf("root->data = %d   min=%d  max=%d\n",root->data,min,max);
	return(root->data > min && root->data < max && checkifBST(root->left,min,root->data) && checkifBST(root->right,root->data,max));

}


void createDLL(struct tree *root,struct tree **head,struct tree **tail) {
      /*  not working 
       static struct tree *prev=NULL,*temp;
       static int i=0;
       if(root == NULL)
              return;
       if(prev != NULL)
       printf("root = %d prev = %d\n",root->data,prev->data);
       else {
       printf("root = %d\n",root->data);
       }
       createDLL(root->left,head);
       if(*head == NULL){
              *head = root;
              root->left = root->right = NULL;
       }
       else {
              root->left = prev;
              temp=*head;
              while(temp != prev) {
                     printf("temp = %d\n",temp->data);
                     temp=temp->right;
                     if(i==10) break;
                     i++;
              }
              temp->right = root;
       }
       prev = root;
       //root->right=NULL;
       printf("prev = %d\n",prev->data);
       createDLL(root->right,head);
    //   root->right = NULL;
        */
        
        // traverse inorder and manipulate the tree
        struct tree *temp = *head;
        struct stack *s = createStack(15);
        while(1) {
        	while(root!= NULL) {
        		push(s,root);
        		root = root->left;
        	}
        	if(s->top == -1)
        		break;
        	root = pop(s);
        	if(*head == NULL) {
        		temp = root;
        		*head = temp;	
        	}
        	else {
  //      		printf("temp = %d root =%d\n",temp->data,root->data);
        		temp->right = root;
        		root->left = temp;
        		temp = root;
        		*tail = temp;
        	}
        	
        	root=root->right;
        }
       // temp->right =NULL;
        deleteStack(s);
}

void traverseDLL(struct tree *head) {
//	int i=0;
       while(head != NULL) {
              printf(" %d ",head->data);
              head = head->right;
       }
       printf("\n");

}

void traverseSLLReverse(struct tree *tail)  {
	while (tail != NULL) {
		printf(" %d ",tail->data);
		tail = tail->left;
	}

}

struct tree *DLLToTree(struct tree *head) {

	struct tree *temp,*p,*q;
	if(head == NULL || head->right == NULL) {
		return NULL;
	}
	temp = findMidOfDll(head);
	printf("processing %d\n",temp->data);
	p=head;
	// now divide the DLL from temp in two dll
	if(p != temp) {
		while(p->right != temp)
			p=p->right;
	}
	q=temp->right;
	p->right=NULL;
	q->left=NULL;
	// now build the left tree
	temp->left = DLLToTree(head);
	// now create the right tree
	temp->right = DLLToTree(q);
	return temp;
}
struct tree *findMidOfDll(struct tree *head) {
	struct tree *slow,*fast;
	slow=head;
	fast=head;
	// if DLL has more than 2 node then move else return the first as middle	
	if(fast->right->right != NULL)
		while(slow !=NULL && fast != NULL && fast->right!=NULL){
			fast=fast->right->right;
			slow =slow->right;
		}
	return slow;
}

struct tree * findkthsmallele(struct tree *root,int kth) {
//	static int count=0;
	struct tree *temp;
	if(root == NULL)
		return NULL;
	temp = findkthsmallele(root->left,kth);	
	if(temp != NULL)
		return temp;
//	printf("processing : %d count = %d\n",root->data,count);
	count++;
	if(count == kth)
		return root;
	return findkthsmallele(root->right,kth);
}

void printRange_1 (struct tree *root,int k1, int k2) {
	if(root == NULL)
		return;
	if(root->data >= k1)
		printRange_1 (root->left,k1,k2);
	if(root->data >= k1 && root->data <= k2)
		printf(" %d ",root->data);
	if(root->data <= k2)
		printRange_1 (root->right,k1,k2);
}

