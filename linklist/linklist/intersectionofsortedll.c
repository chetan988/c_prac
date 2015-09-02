#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node * next;
};


void addNode(struct node **,int);
void printNodes (struct node **);
struct node * intersection(struct node*,struct node *);
int main() {
	struct node *head1 = NULL, *head2 = NULL;
	addNode(&head1,10);
	
	
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
