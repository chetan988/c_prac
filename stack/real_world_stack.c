#include<stdio.h>
#include<stdlib.h>

#define capacity 3 // a stack can have maximum 10 element
#define stackcapacity 3 // stack of stack can have 3 stack

struct innerstack {
	int data[capacity];
	int innertop;
};


struct stack {
	struct innerstack si[stackcapacity];
	int top;
};

struct stack *initialize() {
	int i,j;
	struct stack *s = (struct stack *) malloc (sizeof(struct stack));
	s->top=-1;
	for(i=0;i<stackcapacity;i++)
		s->si[i].innertop = -1;
	return s;
}

void push(struct stack *s,int data) {
	printf("inserting element : %d\n",data);
	if(s->si[stackcapacity-1].innertop == capacity-1){
		printf("stack is full\n");
		return;
	}
	if(s->top == -1)
		s->top++;
	if(s->si[s->top].innertop == capacity-1) { 
		printf("%d stack is full, selecting next stack\n",s->top);
		if(s->top == stackcapacity-1) {
			printf("ohh snap, ran out of stack\n");
			return;
		}
		s->top++;
	}
	s->si[s->top].innertop++;
	s->si[s->top].data[s->si[s->top].innertop] = data;
}

void display(struct stack *s) {
	int i,j;
	for(i=0;i<= s->top;i++) {
		printf("stack no : %d \n",i);
		for(j=0;j<= s->si[i].innertop; j++) {
			printf("%d\n",s->si[i].data[j]);
		}
	}
	
}

int pop(struct stack *s) {
	if(s->top == -1 || s->si[0].innertop == -1) {
		printf("stack is empty\n");
		return;
	}
	
	if(s->si[s->top].innertop == -1) {  // current stack is empty switch to prev stack
		printf("current stack is empty switch to prev stack\n");
		s->top--;
	}
	if(s->top == -1) {
		printf("ohh snap ran out of stack\n");
		return;
	}
	int value = s->si[s->top].data[s->si[s->top].innertop];
	s->si[s->top].innertop--;
	return value;
}


int main() {
	int i;
	struct stack *s = initialize();
	
	for(i=0;i<15;i++) {
		push(s,i);
	}
	display(s);
	for(i=0;i<15;i++) {
			printf("data = %d\n",pop(s));
		}
	
	return 0;
}