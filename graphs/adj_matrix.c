#include<stdio.h>
#include<stdlib.h>

struct graph_m * create_adj_matrix_graph();

struct graph_m {
	int v; 	// number of vertex
	int e;	// number of edege
	int **adj;	// 2d array to store 0/1
};

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


void bfs(struct graph_m *g,int n) {
	struct queue *q = initializeQueue((g->v)*2);
	int visited[g->v],i;
	for(i=0;i<g->v;i++)
		visited[i] = 0;
	enqueue(q,n);
	visited[n] =1;
	while(!isEmpty(q)) {
		n = dequeue(q);
		printf("%d ",n);
		for(i=0;i<g->v;i++) {
			if(g->adj[n][i] == 1 && visited[i] != 1) {
				enqueue(q,i);
				visited[i] = 1;
			}
		}
	}
}

void dfs(struct graph_m *,int);
void dfsUtil(struct graph_m *g,int n, int *visited);

int main() {
	printf("creating graph\n");
	struct graph_m *graph = create_adj_matrix_graph();
	
	printf("graph created\n");
	dfs(graph,2);
	printf("\n");
	
	bfs(graph,2);
	printf("\n");
	
	return 0;
}

void dfs(struct graph_m *g,int n) {
	int visited[g->v];
	int i;
	for(i=0;i<g->v;i++)
		visited[i] =0;
	dfsUtil(g,n,visited);
}

void dfsUtil(struct graph_m *g,int n, int *visited) {
	int i;
	visited[n] = 1;
	printf("%d ",n);
	for(i=0;i<g->v;i++) {
		if(g->adj[n][i]== 1 && visited[i] != 1)
			dfsUtil(g,i,visited);
	}
}
struct graph_m * create_adj_matrix_graph() {

	// allocate memory
	int u, v, e;
	struct graph_m *graph = (struct graph_m *) malloc(sizeof(struct graph_m));

	if (graph == NULL) {
		printf("Memory error\n");
		return NULL;
	}

	printf("Enter the number of vertex: ");
	scanf("%d", &graph->v);

	printf("Enter the number of edege: ");
	scanf("%d", &graph->e);
	// allocate memory for 2d array
	graph->adj = (int **) malloc((graph->v) * sizeof(int));
	for(u=0;u<graph->v;u++)
		graph->adj[u] = (int *) malloc ((graph->v) * sizeof(int));
	for (u = 0; u < graph->v; u++)
		for (v = 0; v < graph->v; v++) {
			if (u == v)
				graph->adj[u][v] = 1;
			else
				graph->adj[u][v] = 0;
		}
    printf("graph has %d vertex and %d edege\n",graph->v,graph->e);
	for (e = 0; e < graph->e; e++) {
		printf("Enter the edege node index: ");
		scanf("%d %d", &u,&v);
		printf("creating a edege between %d <-> %d\n",u,v);
		graph->adj[u][v] = 1;
		graph->adj[v][u] = 1;
	}

	// traverse the matrix

	for (u = 0; u < graph->v; u++) {
		for (v = 0; v < graph->v; v++)
			printf("%d ", graph->adj[u][v]);
		printf("\n");
	}
	return graph;
}
