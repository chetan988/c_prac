#include<stdio.h>
#include<stdlib.h>
#include "adj_matrix.c"

int main() {
	printf("creating graph\n");
	struct graph_m *graph = create_adj_matrix_graph();
	printf("graph created\n");
	return 0;
}
