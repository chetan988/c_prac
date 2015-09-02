#include <stdio.h>
#include <stdlib.h>
/*                    banner
 * 
 *    get the last Nth value of the link list 
 * 
 */
struct node {
	int data;
	struct node * next;
};

void printNodes (struct node **);
void pushNode(struct node **, int);
int getlastN(struct node * , int , int);
int main() {
	
	int ch,pos, data;
	struct node *head=NULL;
	printf("creating linklist....\n");
	pushNode(&head,100);
	pushNode(&head,90);
	pushNode(&head,80);
	pushNode(&head,70);
	pushNode(&head,60);
	pushNode(&head,50);
	pushNode(&head,40);
	pushNode(&head,30);
	pushNode(&head,20);
	pushNode(&head,10);
	printf(" done creating linklist....\n\n");
	printNodes(&head);
	printf("\n enter the N value: ");
	scanf("%d",&pos);
	printf("\t some possible methods\n------------------------\n");
	printf("\t 1. travers twice to get last N element\n\n");
	printf("\t 2. recusive method \n\n");
	printf("\t 3. two pointer method\n\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);
	
	switch(ch) {
		
		case 1:
			data = getlastN(head,pos,1);
			break;
		case 2:
			data = getlastN(head,pos,2);
			break; 
		case 3:
			data = getlastN(head,pos,3);
			break;
		default :
			printf("Wrong choice..\n");
	}
	if(data != -1)
		printf("last nth value is : %d\n\n",data);
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

int getlastN(struct node *n, int pos, int ch) {
	int len=0;
	static int i;
	struct node *temp = n;
	if(n == NULL)   
		return -1;    // empty link list
	if (ch == 1) {
		
		while(temp != NULL) {
			len++;
			temp = temp->next;
		}
		printf("length of the link list : %d \n",len);
		if(len < pos) {
			return -1;   // overflow
		}
		temp = n;   // resret temp
		for(i=1; i< len -pos +1;i++)
			temp = temp->next;
		return (temp->data);
	}
	else if(ch == 2 ) {
		
		if(temp == NULL)
			return;
		getlastN(temp->next,pos,ch);   // call recursively
		i++;                           // back tracking
		printf("i = %d, pos =  %d, data = %d\n",i,pos, temp->data);
		if(i == pos) {
			return (temp->data);
		}
	}
	
	else if (ch == 3) {
		struct node *fast = n, *slow = n;
		int j = 1;
		while(j++<pos)
			fast=fast->next;
printf("data= %d\n",fast->data);   
		while(fast->next!= NULL){
			fast=fast->next;    // will travel length - n
			slow=slow->next;    // will travel n from last
		}
		return (slow->data);
		
	}
}