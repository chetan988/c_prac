#include<stdio.h>
#include "stack.h"

/* program to reverse a stack using stack opration only */

void reverseStack(struct stack *s);
void reverseEachElement(struct stack *s,int );

void main() {

  int i,val;
  struct stack *s = createStack(5);
  for (i=0;i<5;i++){
       printf("Enter the %d value : ",i);
       scanf("%d", &val);
       push(s,val);
  }
  printStack(s);
  printf("reversing the stack\n");
  reverseStack(s);
  printf("\n=================\n");
  printStack(s);
}

void reverseStack(struct stack *s) {
    int cur_val;
    if(isEmpty(s)==1){
       return;
    }
    cur_val = pop(s);
    reverseStack(s);
    printf("reversing : %d\n",cur_val);
    reverseEachElement(s,cur_val);

}

void reverseEachElement(struct stack *s,int data) {
    printf("reversing data : %d\n",data);
    int temp;
    if(isEmpty(s)==1) {
       push(s,data);
       return;
    }
    temp = pop(s);
    reverseEachElement(s,data);
    push(s,temp);

}

