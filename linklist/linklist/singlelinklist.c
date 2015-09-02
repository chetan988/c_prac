#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	
	int data;
	struct node *next;
};
void addNode(struct node **,int);
void printNodes (struct node **);
void pushNode(struct node **, int);
void addNodeAfter(struct node **, int,int);
void addNodeBefore(struct node **, int,int);
void deleteNodeAt(struct node **, int,int);
void deleteNodeN(struct node **, int , int);
int getNnode(struct node *, int pos);
void deletenode (struct node *);
int findMiddleElement(struct node *);
void deleteLinklist(struct node **);
void reverseLinklist(struct node **);
void recReverseLinklist(struct node **);
void detectLoop(struct node *);
int checkPalendrum(struct node **, struct node *);
void insertSortedNode(struct node **, int);
void removesorrectedduplicate(struct node **);
void removeunsorrectedduplicate(struct node **);
int main(int argc, char **argv)
{
	struct node *head = NULL,*head_ref;
	int choice,val,pos,stpos,enpos,subchoice,res;
    while (1){
		printf("\t==========================\n\n\t    operation on linklist    \n\n\t==========================\n");
		printf("\n\t 1 . append a node / add node\n");
		printf("\n\t 2 . push a node\n");
		printf("\n\t 3 . insert a node after\n");
		printf("\n\t 4 . insert a node before\n");
		printf("\n\t 5 . delete a node at\n");
		printf("\n\t 6 . delete node start - end\n");
		printf("\n\t 7 . get node at \n");
		printf("\n\t 8 . find middle element\n");
		printf("\n\t 9 . show link list\n");
		printf("\n\t 10. delete linklist\n");
		printf("\n\t 11. reverse linklist\n");
		printf("\n\t 12. detect loop in linklist\n");
		printf("\n\t 13. check if palendrum\n");
		printf("\n\t 14. insert value to sorted linklist\n");
		printf("\n\t 15. remove duplicate from sorted link list\n");
		printf("\n\t 16. remove duplicate from unsorted link list\n");
		printf("\n\t 20 . Exit\n\n");
		printf("\nEneter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			
			case 1:
			    printf("\nenter the data: ");
				scanf("%d",&val);
				addNode(&head,val);
				printNodes(&head);
				break;
			case 2:
				printf("\nenter the data: ");
				scanf("%d",&val);
				pushNode(&head,val);
				printNodes(&head);
				break;
			case 3:
				printf("\nenter the position: ");
				scanf("%d",&pos);
				printf("\nenter the data: ");
				scanf("%d",&val);
				addNodeAfter(&head,val,pos);
				printNodes(&head);
				break;
			case 4:
				printf("\nenter the position: ");
				scanf("%d",&pos);
				printf("\nenter the data: ");
				scanf("%d",&val);
				addNodeBefore(&head,val,pos);
				printNodes(&head);
				break;
			case 5:
			    printf("\n\t-----------------------------\n\t        sub menu       \n\t---------------------\n");
				printf("\n\t 1 . impementation 1\n");
				printf("\n\t 2 . implementation 2\n");
				printf("enter your choice: ");
				scanf("%d",&subchoice);
				printf("\nenter the position: ");
				scanf("%d",&pos);
				switch(subchoice){
					case 1:
						deleteNodeAt(&head,pos,1);
					case 2:
						deleteNodeAt(&head,pos,2);
				}
				printNodes(&head);
				break;
			case 6:
			    printf("\nenter the starting position for delete: ");
				scanf("%d",&stpos);
				printf("\nenter the ending position for delete: ");
				scanf("%d",&enpos);
				deleteNodeN(&head,stpos,enpos);
				printNodes(&head);
				break;
			case 7:
				printf("\nenter the position: ");
				scanf("%d",&pos);
				printf("the node value is : %d\n\n", getNnode(head,pos));
				break;
			case 8:
			     printf("the middle element is : %d\n",findMiddleElement(head));
				 break;
			case 9:
			    printNodes(&head);
				break;
			case 10:
			    deleteLinklist(&head);
				printNodes(&head);
				break;
			case 11:
				printf("\n\t-----------------------------\n\t        sub menu       \n\t---------------------\n");
				printf("\n\t 1 . impementation 1(iterative method)\n");
				printf("\n\t 2 . implementation 2(recuuresive method)\n");
				printf("enter your choice: ");
				scanf("%d",&subchoice);
				switch(subchoice) {
					
					case 1:
						printf("before \n");
						printNodes(&head);
						reverseLinklist(&head);
						printf("after \n");
						printNodes(&head);
						break;
					case 2:
						printf("before \n");
						printNodes(&head);
						recReverseLinklist(&head);
						printf("after \n");
						printNodes(&head);
						break;
				}
			case 12:
				detectLoop(head);
				break;
			case 13:
				head_ref=head;
			    res = checkPalendrum(&head,head);
				head = head_ref;
				if(res==1)
					printf("the link list is palendrum\n");
				else
					printf("the link list is not palendrum\n");
				break;
			case 14:
				printf("\nenter the data: ");
				scanf("%d",&val);
				insertSortedNode(&head,val);
				printNodes(&head);
				break;
			case 15:
				removesorrectedduplicate(&head);
				printNodes(&head);
				break;
			case 16:
				removeunsorrectedduplicate(&head);
				printNodes(&head);
				break;
			case 20:
				break;
		}
		if(choice == 20)
			break;
	}
	return 0;
}

void printNodes (struct node ** head_ref) {
	struct node *temp = *head_ref;
	printf("\n----------------\nlinklist contain: \n----------------\n");
	while(temp != NULL) {
		printf("%d   ",temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}

void addNode(struct node ** head, int val) {
	
	// create a temp node
	struct node *temp = (struct node * ) malloc (sizeof(struct node));
	struct node *last = *head;   // use this to travers to last of noad and add the noad
	temp->data = val;
	temp->next=NULL;
	if(*head == NULL) {
		*head = temp;
	}
	else {
		while(last->next != NULL){
			last = last->next;
		}
		last->next= temp;
	}
	
}

void pushNode(struct node ** head, int val) {
	
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	temp->data = val;
	temp->next = *head;
	*head = temp;
}


void addNodeAfter (struct node ** head,int val,int pos) {
	struct node *new_node = (struct node *) malloc (sizeof(struct node));
	int count=0;
	struct node *temp = *head;
	new_node->data = val;
	if(temp == NULL) 
		pushNode(head,val);
	else {
		while(temp->next != NULL) {
			if(count == pos) {
				new_node->next = temp->next;
				temp->next = new_node;
				count = -1;
				break;
			}
			count++;
			temp = temp->next;
		}
		if(count != -1) {
			printf("pos is higher than available node so appending the new node at the end\n");
			new_node->next =NULL;
			temp->next = new_node;
		}
		
	}
}

void addNodeBefore(struct node ** head,int val,int pos) {
	struct node *new_node = (struct node *) malloc (sizeof(struct node));
	int count=0;
	struct node *temp = *head;
	new_node->data = val;
	if(temp == NULL || pos == 0) 
		pushNode(head,val);
	else {
		while(temp->next != NULL) {
			if(count == pos-1) {
				new_node->next = temp->next;
				temp->next = new_node;
				count = -1;
				break;
			}
			count++;
			temp = temp->next;
		}
		if(count != -1) {
			printf("pos is higher than available node so appending the new node at the end\n");
			new_node->next =NULL;
			temp->next = new_node;
		}
	}
}

void deleteNodeAt(struct node ** head,int pos, int choice) {
	int count = -1;
	struct node *temp = *head;
	if(choice == 1) {
	if(temp == NULL) 
		printf("link list is empty to delete\n");
	else if (pos == 0)
		*head = temp->next;
	else {
		while (temp->next != NULL) {
			count++;
			if(count == pos-1){
				// found the element to drop
				printf("item found ... deleting %d\n",temp->next->data);
				temp->next = temp->next->next;
				count = -2;
				break;
			}
			temp = temp->next;
		}
		if(count !=-2)
			printf("position not found in the link list\n");
	}
	
	}
	else {
		count++;
		while (temp != NULL){
			if(count == pos)
				deletenode(temp);
			count++;
			temp = temp->next;
		}
	}
}

void deletenode(struct node *n) {
	
	if(n == NULL || n->next == NULL)  // can not delete the last node with this method
		return;
	else {
		struct node *temp = n->next;   // store the next node in temp
		n->data = temp->data;		   // copy the next node info into current node
		n->next = temp->next;		   // delete the next node
		free(temp);
	}
}

void deleteNodeN (struct node ** head, int st, int en) {
	
	struct node *temp1 = *head,*temp=NULL;
	int count =0;
	if(temp1 == NULL) {
		printf("link list is empty to delete\n");
		return;
	}
	if (st != 0){
		while (count != st-1 && temp1->next != NULL) {
			count++;
			temp1= temp1->next;
		}
		if(count == st-1)
			temp = temp1;
		else {
			printf("start point is out of linklist bound\n");
			return;
		}
			
	}
	while(count != en && temp1->next != NULL){
		count++;
		temp1 = temp1->next;
	}
	if(st ==0)
		*head = temp1->next;
	else
		temp->next = temp1->next;
	
}

int getNnode(struct node *head, int pos) {
	
	struct node *temp = head;
	int count = 0;
	while(temp != NULL) {
		if(count == pos)
			return (temp->data);
		count++;
		temp = temp->next;
	}
	assert(0);
}

int findMiddleElement (struct node *n) {
	struct node *fast = n, *slow=n;
	if(n ==  NULL)
		assert(0);
	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;    // move faster two times
		slow = slow->next;  		// move slower one time
	}								// by the time fast reach end of the node slow will be at the middle

	return(slow->data);
}

void deleteLinklist (struct node **n) {
	/*   method 1
	  struct node *temp = *n,*current = *n;
	while(current != NULL) {
		temp = current;
		current=current->next;
		printf("deleting ... %d\n",temp->data);
		free(temp);  // at the end we are deleting the current and temp because current is temp->next=null
	} 				// so we have to explicitly make *n null
	*n = NULL;
	
	 
	*/
	/*   method 2   */
	struct node *temp = *n;
	if(temp == NULL)
		return;
	printf("iterate .... %d\n",temp->data);
	deleteLinklist(&(temp->next));
	printf("deleting .... %d\n",temp->data);
	free(temp);
	*n = NULL;
}

void reverseLinklist (struct node **head_ref) {
	struct node *current= *head_ref,*next,*prev=NULL;
	if(current == NULL)
		return;   // single or no element
	while(current != NULL) {
		next = current->next;		//store next value
		current->next = prev;		//pint current element to reversed linklist
		prev = current;				// put the current into prvered catagory
		current = next;				// move to next node
	}
	*head_ref = prev;				// adjust the head
}

void recReverseLinklist (struct node **head_ref) {
	struct node *current = *head_ref, *rest = (*head_ref)->next;
	if(rest == NULL) {
		return;
	}
	recReverseLinklist(&rest);
	current->next->next = current;
	current->next=NULL;
	*head_ref = rest;
}
/* floyed cycle detect algo */
void detectLoop(struct node * n) {
	
	struct node *temp=n,*fast=n,*slow=n;
	
	 // creating a loop
	while(temp->next != NULL) 
		temp = temp->next;
	temp->next = n->next->next;  // loop to the sesond element
	
	while(slow && fast && fast->next) {
		slow= slow->next;
		fast = fast->next->next;
		if(slow == fast){
			printf("loop detected at %d\n\n",slow->data);
			return;
		}
	}
	printf("No loop detected\n");
}


int checkPalendrum (struct node **first, struct node * last) {
	int flag;
	if(last == NULL)
		return 1;
//	printf("iteration of last ->%d\n",last->data);
	flag = checkPalendrum(first,last->next);  // keep the first constant and increment the last for back tracking
	if(flag == 0) {   // if not palendrum returned no need to check just return 0 for next iteration
//		printf("one data mismatch found\n");
		return 0;
	}
//	printf("first = %d  last = %d\n",(*first)->data,last->data);
	if((*first)->data == last->data) {
		*first = (*first)->next;
		return 1;
	}
	return 0;		
}

void insertSortedNode (struct node **head_ref, int val) {
	
	struct node *new_node = (struct node *) malloc (sizeof(struct node));
	new_node->data = val;
	
	if ((*head_ref == NULL) || (*head_ref)->data >= new_node->data) {		// empty link or node to be insered first list add the new node 
		new_node->next = *head_ref;
		*head_ref = new_node;
		return;
	}
	struct node *temp = *head_ref;
	while(temp->next != NULL && temp->next->data < new_node->data)
		temp = temp->next;
	
	new_node->next = temp->next;
	temp->next = new_node;
	
}

void removesorrectedduplicate(struct node **head){
	
	struct node *temp = *head,*next_node;
	while(temp->next != NULL){
		if(temp->data == temp->next->data) {
			printf("removing .. %d\n",temp->data);
			next_node = temp->next->next;
			free(temp->next);
			temp->next = next_node;
		}
		else {
			temp=temp->next;
		}
	}
}

void removeunsorrectedduplicate (struct node ** head_ref) {
	
	struct node *current=*head_ref, *next_node=*head_ref,*temp;
	while(current != NULL && current->next != NULL) {
		printf("current = %d\n",current->data);
		next_node = current;
		while(next_node->next != NULL) {
			printf("next_node = %d\n",next_node->next->data);
			if(current->data == next_node->next->data) {
				printf("dupplicate found = %d\n",current->data);
				temp = next_node->next->next;
				free(next_node->next);
				next_node->next = temp;
			}
			else {
				next_node = next_node->next;
			}
		}
		current = current->next;
	}
}