#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

void printNodes (struct node *);
void pushNode(struct node *, int);
void deletenode(struct node *);
int main() {
	
	struct node head;
	head.data=0;
	head.next=NULL;
	printf("creating linklist....\n");
	pushNode(&head,100);
	printf("head = %d\n",head.data);
	pushNode(&head,90);
	printf("head = %d\n",head.data);
	pushNode(&head,80);
	printf("head = %d\n",head.data);
	pushNode(&head,70);
	printf("head = %d\n",head.data);
	pushNode(&head,60);
	printf("head = %d\n",head.data);
	pushNode(&head,50);
	pushNode(&head,40);
	pushNode(&head,30);
	pushNode(&head,20);
	pushNode(&head,10);
	printNodes(&head);
	//deletenode(head);
	//printNodes(head);
	//deletenode(head);
	//printNodes(head);
	return 0;
	
}

void pushNode(struct node * head, int val) {
	
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	temp->data = val;
	temp->next = head;
	head = temp;
}

void printNodes (struct node * head_ref) {
	struct node *temp = head_ref;
//	printf("%d   ",temp->data);
//	return;
	printf("\n----------------\nlinklist contain: \n----------------\n");
	while(temp != NULL) {
		printf("%d   ",temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}

void deletenode(struct node *head_ref) {
	
	struct node *temp;
	temp = head_ref;
	head_ref = head_ref->next;
	free(temp);
}