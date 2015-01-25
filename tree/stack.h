#ifndef stack_h

#define stack_h
struct stack {

	struct tree **data;
	int top;
	int capacity;
};

struct stack * createStack(int);
void push (struct stack*,struct tree*);
struct tree* pop (struct stack*);


#endif