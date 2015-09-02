#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

void printNodes (struct node **);
void pushNode(struct node **, int);
void swapPair(struct node **);

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
	swapPair(&head);
	printNodes(&head);
	return 1;
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

void swapPair(struct node ** head_ref) {
/*	
	struct node *current = *head_ref;
    struct node *next_node = current->next;
	int temp;
	//printf("current = %d and next = %d\n",current->next,next_node->next);
	
    while(1){
		printf("swapping %d <-> %d\n",current->data,next_node->data);
		temp = current->data;
		current->data = next_node->data;
		next_node->data = temp;
		if(current->next->next != NULL && next_node->next->next != NULL) {
			current = current->next->next;
			next_node= next_node->next->next;
		}
		else
			break;
		printf(" next in queue swapping %d <-> %d\n",current->data,next_node->data);
	}
*/ 

	struct node *current = *head_ref;
	int temp;
	
	while(current != NULL && current->next != NULL) {
		temp = current->data;
		current->data = current->next->data;
		current->next->data = temp;
		current = current->next->next;
	}
}