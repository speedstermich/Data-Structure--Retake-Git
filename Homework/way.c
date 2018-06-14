#include <stdio.h>
#include <stdlib.h>
#include "way_class.h"
#include "print_path.h"

void Insert_Edge(int seq, Vertex *head, int end)
{
	Edge *rear = head -> link;
	Edge *newEdge = (Edge *)malloc(sizeof(Edge));

	newEdge -> seq = seq;
	newEdge -> adjvex = end;
	newEdge -> next = NULL;
	if(rear == NULL)
	{
		head -> link = newEdge;
	}
	else
	{
		while(rear -> next != NULL)
			rear = rear -> next;
			rear -> next = newEdge;
	}
}

void DFS()
{
	
}
int main(int argc, char const *argv[]) {
	Adjlist *adjlist;
	int n, e;
	int seq, v1, v2, i;

	scanf("%d %d", &n, &e);
	adjlist = Create_Adjlist(n);
	for ( i = 0; i < e; i++ )
	{
		scanf("%d %d %d", &seq, &v1, &v2);
		Insert_Edge(seq, &(adjlist -> list[v1]), v2);
		Insert_Edge(seq, &(adjlist -> list[v2]), v1);
	}

return 0;
}
