#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



struct queue * createqueue(int n) {
    printf("creating a queue of size %d\n",n);
    struct queue *temp = (struct queue *) malloc (sizeof(struct queue));
    if(temp == NULL)
       printf("can not create the queue");
    else {
       temp->capacity = n;
       temp->front=temp->rear=-1;
       temp->data = (struct tree *) malloc (temp->capacity * sizeof(struct tree));
    }
    return temp;
}

void enqueue (struct queue* s,struct tree val){
    if(s->rear == s->capacity -1){
        printf("queue is full\nqueueoverflow occured\n");
        return;
    }
    else {
	  if(s->rear == -1)
	     s->front=0;
      s->rear++;
      s->data[s->rear] = val;
     // printf("Entering s->data[%d] = %d\n",s->top,val);
      return ;
    }
}

struct tree dequeue(struct queue* s) {
  struct tree temp;
  if(s->front == -1) {
    printf("queue is empty\nqueueunderflow occured\n");
    return temp;
  }
  else {
     temp=s->data[s->front];
	if(s->front == s->rear)
	   s->front=s->rear=-1;
	 else
	   s->front++;
     return temp;
  }
}

void deletequeue(struct queue* s) {
     free(s->data);
     free(s);
}
/*
void printqueue(struct queue* s) {
        int i;
        if(isEmpty(s)) {
            printf("queue is empty\n");
           return;
        }
        else {
            printf("front = %d  rear=%d\n",s->front,s->rear);
            for (i=s->front; i<= s->rear;i++)
                printf("s->data[%d] = %d  ",i,s->data[i]);
        }
        printf("\n");
}

int isEmpty(struct queue* s) {
    if(s->front == -1)
         return 1;
    else
         return 0;
}
int isFull (struct queue* s) {
   if(s->rear == s->capacity -1)
        return 1;
    else
         return 0;
}
*/
