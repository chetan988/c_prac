#ifndef queue_h
#define queue_h
struct queue {

	struct tree *data;
	int rear,front;
	int capacity;
};

struct queue * createqueue(int);
void enqueue (struct queue*,struct tree);
struct tree dequeue (struct queue*);
//int getTopVal(struct queue*);
//int getTopEle(struct queue*);
//void deletequeue(struct queue*);
//void printqueue(struct queue*);
//int isEmpty(struct queue*);
//int isFull (struct queue*);

#endif

