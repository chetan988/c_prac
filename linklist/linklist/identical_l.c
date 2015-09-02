/*

dentical Linked Lists
Two Linked Lists are identical when they have same data and arrangement of data is also same. 
For example Linked lists a (1->2->3) and b(1->2->3) are identical. .
 Write a function to check if the given two linked lists are identical.
 
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "insertnode.h"

 int isIdentical(struct node*, struct node*);
 int isIdenticalrecc (struct node*, struct node*);
int main() {
	
	struct node *head1 = NULL,*head2 = NULL;
	int flag=0;
	addNode(&head1,12);
	addNode(&head1,15);
	addNode(&head1,10);
	addNode(&head1,11);
	addNode(&head1,5);
	addNode(&head1,6);
	addNode(&head1,2);
	addNode(&head1,3);

	addNode(&head2,12);
	addNode(&head2,15);
	addNode(&head2,10);
	addNode(&head2,11);
	addNode(&head2,5);
	addNode(&head2,6);
	addNode(&head2,2);
	addNode(&head2,3);

/*
    addNode(&head1,12);
	addNode(&head1,15);
	addNode(&head1,10);
	addNode(&head1,11);
	addNode(&head1,5);
	addNode(&head1,6);
	addNode(&head1,2);
	addNode(&head1,3);

	addNode(&head2,12);
	addNode(&head2,15);
	addNode(&head2,10);
	addNode(&head2,1);
	addNode(&head2,5);
	addNode(&head2,6);
	addNode(&head2,2);
	addNode(&head2,3);
*/
	printNodes(&head1);
	printNodes(&head2);
	
	flag=isIdenticalrecc(head1,head2);
	if(flag == 0)
		printf("both the link list are not same\n\n");
	else
		printf("both the link list are same\n\n");
	return 0;
} 


int isIdentical(struct node *head1,struct node *head2) {
	while(1) {
		if(head1 == NULL && head2 == NULL)
			return 1;
		if(head1 != NULL && head2 == NULL)
			return 0;
		if(head2 != NULL && head1 == NULL)
			return 0;
		if(head1->data != head2->data)
			return 0;
// if we come here above all are false so that means head1->data = head2->data
// so incement the ll
		head1 = head1->next;
		head2 = head2->next;
	}
}

int isIdenticalrecc (struct node *head1, struct node *head2) {
	if(head1 == NULL && head2 == NULL)
		return 1;
	if(head1 != NULL && head2 == NULL)
		return 0;
	if(head2 != NULL && head1 == NULL)
		return 0;
	if(head1->data != head2->data)
		return 0;
	return isIdenticalrecc (head1->next,head2->next);
}