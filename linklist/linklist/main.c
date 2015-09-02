#include <stdio.h>
#include <stdlib.h>

/* create a node with data, node *rand, node *next where rand point to a ranod node
   now copy such a linl list to another link list */

struct node {
	int data;
	struct node *rand;
	struct node *next;
};

void pushNode(struct node ** head, int val);
void addNode(struct node ** head, int val);
void printNodes (struct node ** );
void copy (struct node **,struct node ** );

int main()
{
	struct node *head1=NULL, *head2=NULL;

	// now create head1 link list
	   addNode(&head1,1);
	   addNode(&head1,2);
	   addNode(&head1,3);
	   addNode(&head1,4);
	   addNode(&head1,5);

    // now assign the rand pointer
    // 1->3 , 2->4,3->5,4->null	,5->1
    head1->rand = head1->next->next;  //1->3
    head1->next->rand = head1->next->next->next;  //2->4
    head1->next->next->rand = head1->next->next->next->next;   // 3->5
    head1->next->next->next->rand = NULL;  //4-> null
    head1->next->next->next->next->rand = head1; // 5->1
    printNodes(&head1);
printf("\nnow copying the link list\n");
    copy(&head1,&head2);


}

void copy(struct node **h1,struct node **h2 ) {
     struct node *temp1,*temp2;
     temp1 = *h1;
     // create one memory block (temp2) strore rand =NULL and temp2.next = temp1.rand
     // modify the temp1.rand = temp2
     // so here we saved the random information of temp1 node in temp2 and newly created block temp2 info in temp rand
     // so we will be retrive all the info at the end and rearragene again

     while(temp1 != NULL) {
        temp2 = (struct node *) malloc (sizeof(struct node));
        temp2->next = temp1->rand;     // here tem2 is used as a newly created memory block to store node data temporarili we will re arragne the block to
                                    // create a link list latter
        temp2->data = temp1->data;
        temp1->rand = temp2;
        temp1 = temp1->next;
  //      printf("temp2 = %d temp2->next=%d\n",temp2->data,temp2->next);
     }
//printf("\n\n");
     // now connect the temp2.rand blocks
     temp1 = *h1;
     while(temp1 != NULL) {
         temp2 = temp1->rand; // in above while we saved the temp2 block in temp1->rand
         if(temp2->next == NULL)
            temp2->rand = NULL;   // if rand is null for one node
         else
             temp2->rand = temp2->next->rand;  // temp2->next contain the original temp1->rand(lets say rand1) value and rand1->rand contain the newly
                                           // coressponding newly created block which is suppose to be rand of temp2
         temp1 = temp1->next;
 //        printf("temp2 = %d(%u) temp2->rand=%u\n",temp2->data,temp2,temp2->rand);
      }
//printf("\n\n");
      // now correct the temp1 rand value
      // actual temp1->rand value is stored at temp2->next
      temp1 = *h1;
      h2 = temp1->rand;
  //    printf("h2 = %u  temp1->rand=%u\n",*h2,temp1->rand);
      while(temp1 != NULL) {
          temp2 = temp1->rand;
          temp1->rand = temp2->next;
          if(temp1->next == NULL)
              temp2->next = NULL;   // last element of linklist
          else
              temp2->next = temp1->next->rand;
          temp1 = temp1->next;
    //      printf("temp2 = %d(%u)  temp2->rand = %u  temp2->next = %u\n",temp2->data,temp2,temp2->rand,temp2->next);
      }
      printNodes(&h2);

}




void printNodes (struct node ** head_ref) {
	struct node *temp = *head_ref;
	printf("\n----------------\nlinklist contain: \n----------------\n");
	while(temp != NULL) {
		printf("%d(%u)  -> ",temp->data,temp);
		temp = temp->next;
	}
	printf(" null \n\n");
	temp = *head_ref;
	printf("\n----------------\nlinklist random contain contain: \n----------------\n");
	while(temp != NULL) {
	    if(temp != *head_ref)
	       printf(",");
	    if(temp->rand == NULL)
	       printf(" %d(%u) -> null",temp->data,temp);
	    else
		   printf(" %d(%u) -> %d(%u)",temp->data,temp,temp->rand->data,temp->rand);
		temp = temp->next;
	}
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
