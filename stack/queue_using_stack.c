#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

/* implementing queue with stack
 * we nees two stack one to enqueue and other to dequeue.
 * when we will call enqueue we will push in s1 and whene we will dequeue we will pop from s1 and 
 * push to s2 then pop from s2 and return
 */


struct queue {
	struct stack *s1;
	struct stack *s2;
};

struct queue * initialize (int size) {
	struct queue *q = (struct queue *) malloc (sizeof(struct queue));
	q->s1 = createStack(size);
	q->s2 = createStack(size);
	
	return q;
}


void enqueue (struct queue *q,int data) {
	if(isEmpty(q->s1) && !isEmpty(q->s2)) {  // we have transferred the data from s1 to s2, transfer back
		while(!isEmpty(q->s2))
			push(q->s1,pop(q->s2));
	}
	push(q->s1,data);
}

int dequeue (struct queue *q) {
	if(isEmpty(q->s2) && !isEmpty(q->s1)) {  // we have transferred the data from s1 to s2, transfer back
			while(!isEmpty(q->s1))
				push(q->s2,pop(q->s1));
		}
	return pop(q->s2);
}

void print(struct queue *q) {
	if(isEmpty(q->s2) && !isEmpty(q->s1))
		printStack(q->s1);
	if(isEmpty(q->s1) && !isEmpty(q->s2))
			printStack(q->s2);
		
}


int main() {
	int i;
	struct queue *q = initialize(5);
	for(i=0;i<7;i++) {
		enqueue(q,i);
	}
	for(i=0;i<7;i++) {
			printf("%d \n",dequeue(q));
	}
	return 10;
}