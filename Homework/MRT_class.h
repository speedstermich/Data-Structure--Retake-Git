#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 41
#define INF 0x3f3f3f3f
#define MAXSTATNUM 500

//make Edge class
typedef struct Edge{
	int adjseq;
	int weight;
	int lineseq;
	struct Edge *next;
}edge;

//make station class
typedef struct Station{
	char name[MAXSTRLEN];
	int trans;
	int lineseq;
	int statseq;
	edge *link;
}station;

// make Line class
typedef struct Line{
	int size;
	int seq;
	int isloop;
	station *list;
}line;

// make railway class
typedef struct Railway{
	int size;
	struct Station list[MAXSTATNUM];
}railway;

/*@@requires : Head != NULL*/
void Insert_Edge(station *head, int end, int lineseq)
{// function for insert new Edge
	 edge *rear = head -> link;
	 edge *newEdge = (edge *)malloc(sizeof(edge));
	 if(newEdge == NULL)
	 {
		 printf("ERROR");
		 return;
	 }

	 newEdge -> weight = 1;
	 newEdge -> lineseq = lineseq;
	 newEdge -> adjseq = end;
	 newEdge -> next = NULL;
	 if(rear == NULL)
	 {
		 head -> link = newEdge;
	 }
	 else
	 {
		 while( rear -> next != NULL )
		 	rear = rear -> next;	//reach the rear
		rear -> next = newEdge; // add the new edge @ the rear
	 }
}

void Input_Station(railway *rail, line lines, int seq_inline, int seq_inrail)
{//Input a station in a processed line to a railway system, and  seq_inrail  is railway-> size
	strcpy(rail -> list[seq_inrail].name, lines.list[seq_inline].name);
	rail -> list[seq_inrail].trans = lines.list[seq_inline].trans;
	rail -> list[seq_inrail].lineseq = lines.seq;
	rail -> list[seq_inrail].statseq = seq_inrail;
	rail -> list[seq_inrail].link = NULL;
	rail -> size++;

	if(seq_inline == 0)
 	{// the first station
		if(lines.isloop)
		{// the line is a loop
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[1].statseq, lines.seq);
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[lines.size - 2].statseq, lines.seq);
		}
		else
		{// the start station is not LOOP
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[1].statseq, lines.seq);
		}
	}
	else if (seq_inline == lines.size - 1 - lines.isloop)
	{// last station
		if(lines. isloop)
		{// the line is loop
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[0].statseq, lines.seq);
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[lines.size - 3].statseq, lines.seq);
		}
		else
		{// the last station is not loop
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[lines.size - 2].statseq, lines.seq);
		}
	}
	else
	{
		Insert_Edge(&(rail -> list[seq_inrail]), lines.list[seq_inline + 1].statseq, lines.seq);
		Insert_Edge(&(rail -> list[seq_inrail]), lines.list[seq_inline - 1].statseq, lines.seq);
	}
}

void Update_Station(railway *rail, line lines, int seq_inline, int seq_inrail)
{//update station edges in a railway system
	if(seq_inline == 0)
	{// the first station
		if(lines.isloop)
		{// the line is a loop
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[1].statseq, lines.seq);
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[lines.size - 2].statseq, lines.seq);
		}
		else
		{// the start station is not LOOP
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[1].statseq, lines.seq);
		}
	}
	else if (seq_inline == lines.size - 1 - lines.isloop)
	{// last station
		if(lines. isloop)
		{// the line is loop
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[0].statseq, lines.seq);
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[lines.size - 3].statseq, lines.seq);
			}
		else
		{// the last station is not loop
			Insert_Edge(&(rail -> list[seq_inrail]), lines.list[lines.size - 2].statseq, lines.seq);
		}
	}
	else
	{
		Insert_Edge(&(rail -> list[seq_inrail]), lines.list[seq_inline + 1].statseq, lines.seq);
		Insert_Edge(&(rail -> list[seq_inrail]), lines.list[seq_inline - 1].statseq, lines.seq);
	}
}

int In_Rail(railway rail, char name[])
{// find the station and return its sequence number in railsystems
	int iter_rail;
	for(iter_rail = 0; iter_rail < rail.size; iter_rail++)
	{
		if(strcmp(rail.list[iter_rail].name, name) == 0)
			return iter_rail;
	}
	return -1; //error
}

void Input_Line(railway *rail, line lines)
{// input a processed line into a railway system
	int seq_inline, seq_inrail;
	int seq_fromsize = rail -> size;
	if(rail -> size == 0) //empty systems
	{//initialize a railway system
		for (seq_inline = 0; seq_inline < lines.size; seq_inline++)
		{//in an empty railway system, the inline seq equals the inrail seq
			rail -> list[seq_inline].link = NULL;
			Input_Station(rail, lines, seq_inline, seq_inline);
		};
	}
	else
	{
		for(seq_inline = 0; seq_inline < lines.size - lines.isloop; seq_inline++)
		{
			seq_inrail = In_Rail(*rail, lines.list[seq_inline].name);
			if(seq_inrail != -1)
			{
				Update_Station(rail, lines, seq_inline, seq_inrail);
			}
			else
			{
				Input_Station(rail, lines, seq_inline, seq_fromsize);
				seq_fromsize++;
			}
		}
	}
}

void Process_Line(railway *rail, line *lines)
{//pre -process the statseq of the station in a line
	int seq_inline, seq_inrail;
	if (rail -> list == NULL)
	{//empty railway system
		for (seq_inline = 0; seq_inline < lines -> size; seq_inline++)
		{
			lines -> list[seq_inline].statseq = seq_inline;
		}
	}
	else
	{
		int seq_fromsize = rail -> size;
		for (seq_inline = 0; seq_inline < lines -> size; seq_inline++)
		{
			seq_inrail = In_Rail(*rail, lines ->list[seq_inline].name);
			if(seq_inrail != -1)
			{//this station already exists in the railway station
				lines -> list[seq_inline].statseq = seq_inrail;
			}
			else
			{//new station
				lines -> list[seq_inline].statseq = seq_fromsize;
				seq_fromsize++;
			}
		}
	}
}

void Dijkstra(railway *rail, char startname[], char destname[], int path[])
{
	int start = In_Rail( *rail, startname);
	int dest = In_Rail (* rail, destname);
	int *dist = (int *)malloc(rail -> size * sizeof(int) );

	memset(dist, INF, rail -> size * sizeof(int));
	dist [start] = 0;

	edge *link = rail -> list[start].link;
	while(link != NULL)
	{
		dist[link -> adjseq] = link -> weight;
		path[link -> adjseq] = start;
		link = link -> next;
	}

	while(dist [dest] == INF)
	{
		int min = INF, minstat = dest, iter;
		for(iter = 0; iter < rail -> size; iter++)
		{
			if(dist [iter] != 0 && dist[iter] < min)
			{// not enclosed, and find the minimum
				min = dist[iter];
				minstat = iter;
			}
		}
		link = rail -> list[minstat].link;
		if (link == NULL)
			exit(1);
		while( link != NULL)
		{
			if (dist[minstat] + link -> weight < dist[link -> adjseq])
			{
				dist[link -> adjseq] = dist[minstat] + link ->weight;
				path[link -> adjseq] = minstat;
			}
			link = link -> next;
		}
		dist[minstat] = 0;
	}
	free (dist);
}

int Get_Lineseq(railway rail, int stat1, int stat2)
{
	edge *link = rail.list[stat1].link;
	while(link != NULL)
	{
		if(link -> adjseq == stat2)
			return link -> lineseq;
		link = link -> next;
	}
	return -1;
}

void Depict_path(railway *rail, int start, int dest, int path[])
{
	int *track = (int *)malloc(rail -> size * sizeof(int));
	memset(track, INF, rail -> size * sizeof(int));
	int iter = 0;
	while(dest != start)
	{
		track[iter++] = dest;
		dest = path[dest];
	}
	track[iter] = start;

	int i = 0, j = iter;
	while (i < j)
	{//reverse track[]
		int tmp;
		tmp = track[j];
		track[j] = track[i];
		track[i] = tmp;
		i++, j--;
	}

	int currentstat = 1;
	printf("%s-", rail -> list[track[0]].name);
	for(i = 1; i < iter; i++)
	{
		if( Get_Lineseq( *rail, rail -> list[track[i - 1]].statseq, rail -> list[track[i]].statseq)
		!= Get_Lineseq(*rail, rail -> list[track[i + 1]].statseq, rail -> list[track[i]].statseq) )
		{//previous station and the next is not on the same line
			printf("%d(%d)-%s-", Get_Lineseq(*rail, rail -> list[track[i - 1]].statseq,
				rail -> list[track[i]].statseq), currentstat, rail -> list[track[i]].name);
			currentstat = 1;
		}
		else
		{
			currentstat++;
		}
	}
	printf("%d(%d)-%s\n", Get_Lineseq(*rail, rail -> list[track[i - 1]].statseq,
		rail -> list[track[i]].statseq), currentstat, rail -> list[track[iter]].name);
}
