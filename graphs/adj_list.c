#include<stdio.h>
#include<stdlib.h>

// create a linllist

struct Vertexlist {
	int node;
	struct Vertexlist *next;
};

// create headpointer
struct Vertexpointer {
	struct Vertexlist *head;
};

// create a graph

struct graph_l {
	int vertex;
	struct Vertexpointer *array;
};

// create a queue for bfs

struct queue {
	int *data;
	int front;
	int rear;
	int capacity;
};

struct queue *initializeQueue(int size) {
	struct queue *q = (struct queue *) malloc (sizeof(struct queue));
	q->front = q->rear = -1;
	q->capacity = size;
	q->data = (int *) malloc (size * sizeof(int));
	return q;
}

void enqueue(struct queue *q, int data ) {
	if((q->rear)+1 == q->capacity) {
		printf("queue overflow\n");
		return;
	}
	
	else {
		q->rear++;
		q->data[q->rear]= data;
		if(q->front == -1)
			q->front++;
	}
}

int dequeue(struct queue *q) {
	int value;
	if(q->front == -1) {
		printf("queue empty");
		return;
	}
	else {
		value = q->data[q->front];
		if(q->front == q->rear)
			q->front = q->rear = -1;
		else
			q->front++;
		return value;
	}
}

int isEmpty(struct queue *q) {
	if(q->front == -1)
		return 1;
	return 0;
}

void bfs(struct graph_l *g, int n) {
	struct queue *q = initializeQueue((g->vertex)*2);
	int visited[g->vertex],i;
	for(i=0;i<g->vertex;i++)
		visited[i] = 0;
	enqueue(q,n);
	visited[n] =1;
	while(!isEmpty(q)) {
		n = dequeue(q);
		printf("%d ",n);
		struct Vertexlist *temp = g->array[n].head;
		while(temp) {
			if(visited[temp->node] != 1) {
				enqueue(q,temp->node);
				visited[temp->node] = 1;
			}
			temp = temp->next;
		}
	}
	printf("\n");
}

struct graph_l *createEmptyGraph(int size) {
	int i;
	struct graph_l *graph = (struct graph_l*) malloc (sizeof(struct graph_l));
	graph->vertex = size;
	graph->array = (struct Vertexpointer *) malloc (size * sizeof(struct Vertexpointer));
	for(i=0;i<size;i++)
		graph->array[i].head = NULL;
	return graph;
}

void addEdeg (struct graph_l *graph, int src,int dest) {
	struct Vertexlist *newnode = (struct Vertexlist*) malloc (sizeof(struct Vertexlist));
	newnode->node = dest;
	newnode->next = graph->array[src].head;
	graph->array[src].head = newnode;
	// bidirectional so ceate a new node 
	struct Vertexlist *anothernewnode = (struct Vertexlist*) malloc (sizeof(struct Vertexlist));
	anothernewnode->node = src;
	anothernewnode->next = graph->array[dest].head;
	graph->array[dest].head = anothernewnode;
}

void printGraph(struct graph_l *graph) {
	int i;
	struct Vertexlist *temp;
	for(i=0;i<graph->vertex;i++) {
		printf("%d ->",i);
		temp = graph->array[i].head;
		while(temp) {
			printf("%d ->",temp->node);
			temp= temp->next;
		}
		printf("\n");
	}
	
}

void dfsUtil(struct graph_l *graph,int n,int *visited) {
	visited[n] =1;
	printf("%d ",n);
	struct Vertexlist *temp = graph->array[n].head;
	while(temp) {
		if(visited[temp->node] != 1)
			dfsUtil(graph,temp->node,visited);
		temp = temp->next;
	}
}

void dfs(struct graph_l *graph, int n) {
	int visited[graph->vertex];
	int i;
	for(i=0;i<graph->vertex;i++)
		visited[i]=0;
	dfsUtil(graph,n,visited);
	printf("\n");
}

int main() {
	struct graph_l *graph = createEmptyGraph(5);
	addEdeg(graph,0,1);
	addEdeg(graph,1,2);
	addEdeg(graph,2,3);
	addEdeg(graph,3,4);
	addEdeg(graph,4,1);
	addEdeg(graph,4,0);
	printGraph(graph);
	dfs(graph,2);
	bfs(graph,2);
	return 1;
}