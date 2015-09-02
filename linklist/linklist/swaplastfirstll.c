#include <stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * next;
};
void printNodes (struct node **);
void pushNode(struct node **, int);
void swaplastfirst(struct node **);
int main() {
	
	struct node *head=NULL;
	pushNode(&head,10);
	pushNode(&head,20);
	pushNode(&head,30);
	pushNode(&head,40);
	pushNode(&head,50);
	pushNode(&head,60);
	printNodes(&head);
	printf("swapping nodes\n");
	swaplastfirst(&head);
	printNodes(&head);
	return 0;
}

void pushNode(struct node ** head, int val) {
	
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	temp->data = val;
	temp->next = *head;
	*head = temp;
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

void swaplastfirst(struct node **head_ref) {
	
	struct node *h1=*head_ref,*h2=*head_ref,*h3;
	while(h2->next->next != NULL)
		h2=h2->next;
	h3 = h2->next;
	h3->next = h1;   // point to head
	h2->next = NULL;
	*head_ref = h3;
}