#ifndef insertnode_h
#define insertnode_h
struct node {
	
	int data;
	struct node *next;
};
void addNode(struct node **,int);
void printNodes (struct node **);
void pushNode(struct node **, int);

#endif

