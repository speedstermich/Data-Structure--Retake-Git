#include <stdio.h>
#include <stdlib.h>

typedef struct EdgeNode{
	int adjvex;
	int seq;
	struct EdgeNode *next;
}Edge;

typedef struct VertexNode{
	int seq;
	Edge *link;
}Vertex;

typedef struct Adjlist_Class{
	int size;
 	Vertex *list;
}Adjlist;

Adjlist *Create_Adjlist(int n)
{
	int i;
	Adjlist *adjlist = (Adjlist *)malloc(sizeof(Adjlist));
	adjlist -> list = (Vertex *)malloc(n * sizeof(Vertex));

	adjlist -> size = n;
	for(i = 0; i < n; i++)
	{
		adjlist -> list[i].seq = i;
		adjlist -> list[i].link = NULL;
	}
	return adjlist;
}
