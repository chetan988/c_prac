#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printNodes (struct node **);
void pushNode(struct node **, int);
void addNode(struct node **,int);
int getconvergepoint(struct node *,struct node *);
int getcount(struct node *);
int getintersecpoint(struct node *,struct node *,int);

int main() {
	int indata,c1,c2;
    struct node *head1 = NULL, *head2=NULL;
    addNode(&head1,10); 	
	addNode(&head1,20);
	addNode(&head1,30);
	addNode(&head1,40);
	addNode(&head1,50);
	addNode(&head1,60);
	addNode(&head1,70);
	addNode(&head2,5); 	
	addNode(&head2,10);
	addNode(&head2,15);
	//head2->next->next->next = head1->next;
	//head2 = head1;
	printNodes (&head1);
	printNodes(&head2);
	indata = getconvergepoint(head1,head2);
	if(indata == -1)
		printf("no intersecttion point\n");
	else
        printf("intersection point is %d",indata);	
	printNodes (&head1);
	printNodes(&head2);
	c1 = getcount(head1);
	c2 = getcount(head2);
	printf("len(head1)= %d    len(head2)= %d\n", c1,c2);
	if(c1 >= c2)
		indata = getintersecpoint(head1,head2,c1-c2);
	else
		indata = getintersecpoint(head2,head1,c2-c1);
	if(indata == -1)
		printf("no intersecttion point\n");
	else
        printf("intersection point is %d",indata);
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

int getconvergepoint(struct node *h1,struct node *h2) {
	struct node *t = h2;
	for(; h1!= NULL;h1=h1->next)
		for(h2 = t;h2!=NULL;h2=h2->next) {
			printf("h1 = %d   h2 = %d\n",h1->data,h2->data);
			if(h1==h2)
				return h1->data;
		}
	return -1;
}

int getcount (struct node * h) {
	int count=0;
	while(h != NULL){
		count++;
		h = h->next;
	}
	return count;
}

int getintersecpoint (struct node *h1,struct node *h2,int d) {
	//int i;
	struct node *th1=h1,*th2=h2;
	while(d--){
		th1 = th1->next;
	}
	
	while(th1 != NULL || th2 || NULL) {
		if(th1==th2)
			return th1->data;
		th1 = th1->next;
		th2 = th2->next;
	}
	return -1;
}