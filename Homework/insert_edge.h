#include <stdio.h>
#include <stdlib.h>
#include "way_class.h"

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
