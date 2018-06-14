#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void DFS(int start, int depth, Adjlist adjlist, int path[], int visited[])
{
	if( start == adjlist.size - 1)
	{
		path[depth] = 0;
		print_Path(path);
		return;
	}
	else
	{
		if(!visited[start])
		{
			visited[start] = 1;
			Edge *link = adjlist.list[start].link;
			while (link != NULL)
			{
				path[depth] = link -> seq;
				DFS(link -> adjvex, depth + 1, adjlist, path, visited);
				link = link -> next;
			}
			visited[start] = 0;
			return;
		}
	}
}

void iterate_Path(Adjlist adjlist)
{
	int *path = (int *)malloc(adjlist.size * sizeof(int));
	int *visited = (int *)malloc(adjlist.size * sizeof(int));

	memset( visited, 0, adjlist.size * sizeof(int) );
	DFS(0, 0, adjlist, path, visited);
	free(path);
	free(visited);
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
	iterate_Path(*adjlist);

return 0;
}
