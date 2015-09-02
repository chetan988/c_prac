#include <stdio.h>
#include <stdlib.h>
#include "insertnode.h"

void printNodes (struct node ** head_ref) {
	struct node *temp = *head_ref;
//	int count=0;
	printf("\n----------------\nlinklist contain: \n----------------\n");
	while(temp != NULL) {
		printf("%d   ",temp->data);
		temp = temp->next;
//		count++;
//		if(count==10)
//			break;
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
