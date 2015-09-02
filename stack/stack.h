#ifndef stack_h
#define stack_h
struct stack {

	int *data;
	int top;
	int capacity;
};

struct stack * createStack(int);
int push (struct stack*,int);
int pop (struct stack*);
//int getTopVal(struct stack*);
//int getTopEle(struct stack*);
void deleteStack(struct stack*);
void printStack(struct stack*);
int isEmpty(struct stack*);
int isFull (struct stack*);
void sort (struct stack *);
int peek(struct stack *);

#endif

