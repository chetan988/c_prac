#include <stdio.h>
#include "insertnode.h"

/*    not working  */
void reverse_k_iter(struct node **,int);
void reverse_k_recc(struct node **,struct node,int);

void main() {
	int k=3;
	struct node *root = NULL;
	addNode(&root,10);
	addNode(&root,20);
	addNode(&root,30);
	addNode(&root,40);
	addNode(&root,50);
	addNode(&root,60);
	addNode(&root,70);
	addNode(&root,80);
	addNode(&root,90);
	addNode(&root,100);
	printNodes(&root);
	reverse_k_iter(&root,k);
	printNodes(&root);
	
	
}

void reverse_k_iter(struct node **head, int k) {
	struct node *current = *head;
	struct node *next_n ;
	struct node *prev = NULL, *first;
	int count=0,flag=0;
	while(current != NULL && current->next != NULL && count <= k ) {
		if(count== k && flag == 0){
			*head=prev;
			flag=1;
		}
		if(count == k ) {
			first->next=current;
			count=0;
		}
		if(count == 0) {
			first = current;
		}
		next_n = current->next;
		current->next = prev;
		prev = current;
		current = next_n;
		count++;
		printf("prev = %d    next_n = %d\n",prev->data,next_n->data);
	}
}