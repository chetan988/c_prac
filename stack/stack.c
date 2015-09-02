#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


struct stack * createStack(int n) {
    printf("creating a stack of size %d\n",n);
    struct stack *temp = (struct stack *) malloc (sizeof(struct stack));
    if(temp == NULL)
       printf("can not create the stack");
    else {
       temp->capacity = n;
       temp->top=-1;
       temp->data = (int *) malloc (temp->capacity * sizeof(int));
    }
    return temp;
}

int push (struct stack* s,int val){
    if(s->top == s->capacity -1){
        printf("stack is full\nstackoverflow occured\n");
        return val+1;
    }
    else {
      s->top++;
      s->data[s->top] = val;
     // printf("Entering s->data[%d] = %d\n",s->top,val);
      return val;
    }
}

int pop(struct stack* s) {
  if(s->top == -1) {
    printf("stack is empty\nstackunderflow occured\n");
    return -1;
  }
  else {
    return s->data[s->top--];
  }
}

void deleteStack(struct stack* s) {
     free(s->data);
     free(s);
}

void printStack(struct stack* s) {
        int i;
        if(isEmpty(s)) {
            printf("stack is empty\n");
           return;
        }
        else {
            for (i=0; i<= s->top;i++)
                printf("s->data[%d] = %d  ",i,s->data[i]);
        }
        printf("\n");
}

int isEmpty(struct stack* s) {
    if(s->top == -1)
         return 1;
    else
         return 0;
}
int isFull (struct stack* s) {
   if(s->top == s->capacity -1)
        return 1;
    else
         return 0;
}

int peek(struct stack *s) {
	if(s->top == -1)
		return -1;
	return s->data[s->top];
}

void sort(struct stack *s) {
	int tempdata;
	struct stack *temp = createStack(s->capacity);
	while(!isEmpty(s)) {
		tempdata = pop(s);
		while(!isEmpty(temp) && peek(temp) > tempdata) {	// check top element of temp if it is greater
														//then poped element then pop from new stack and push to old
														//till we find proper position for poped one
			push(s,pop(temp));
		}
		push(temp,tempdata);
	}
	printStack(temp);
}

/*
int main() {

	int i;
	struct stack *s = createStack(5);
	push(s,5);
	push(s,55);
	push(s,30);
	push(s,100);
	push(s,45);
	sort(s);
	return 1;
}

*/
