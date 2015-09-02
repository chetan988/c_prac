#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printNodes (struct node **);
void pushNode(struct node **, int);
void addNode(struct node **,int);
void printreverse(struct node *);
int main(){
	struct node *head=NULL;
	addNode(&head,10);
	addNode(&head,20);
	addNode(&head,30);
	addNode(&head,40);
	addNode(&head,50);
	addNode(&head,60);
	addNode(&head,70);
	printNodes(&head);
	printf("printing in reverse order\n");
	printreverse(head);
	printNodes(&head);
	return 1;
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


void pushNode(struct node ** head, int val) {
	
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	temp->data = val;
	temp->next = *head;
	*head = temp;
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


void printreverse(struct node *h){
	
	if(h==NULL)
		return;
	printreverse(h->next);
	printf("%d  ",h->data);
}