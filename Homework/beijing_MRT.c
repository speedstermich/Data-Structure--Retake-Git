#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MRT_class.h"

#define MAXSTRLEN 41
#define INF 0x3f3f3f3f
#define MAXSTATNUM 500

int main(int argc, char const *argv[]) {
	FILE *fp;
	int linenum, lineseq, statnum, trans;
	int i, j;
	char statname[MAXSTRLEN];
	char startname[MAXSTRLEN], destname[MAXSTRLEN];

	fp = fopen("bgstations.txt", "r");
	if(fp == NULL)
		printf("FAILED TO OPEN");

	railway *beijing = (railway *)malloc(sizeof(railway));
	beijing -> size = 0;
	line *newline = (line *)malloc(sizeof(line));
	fscanf(fp, "%d", &linenum);

	for(i = 1; i <= linenum; i++)
	{
		fscanf(fp, "%d %d", &lineseq, &statnum);
		newline -> seq = lineseq;
		newline -> size = statnum;
		newline -> isloop = 0;
		newline -> list = (station *)malloc(statnum * sizeof(station));
		for(j = 0; j < statnum; j++)
		{
			fscanf(fp, "%s %d", statname, &trans);
			newline -> list[j].lineseq = i;
			strcpy(newline -> list[j].name, statname);
			newline -> list[j].trans = trans;
		}
		if(strcmp(newline -> list[0].name, statname) == 0)
			newline -> isloop = 1;
		Process_Line(beijing, newline);
		Input_Line(beijing, *newline);
		free(newline -> list);
		fscanf(fp, "\n");
	}

	scanf("%s", startname);
	scanf("%s", destname);

	int *path = (int *)malloc(beijing -> size * sizeof(int) );
	Dijkstra(beijing, startname, destname, path);

	Depict_path(beijing, In_Rail(*beijing, startname), In_Rail(*beijing, destname), path);

	free(newline);
	free(path);
	fclose(fp);
	return 0;
}
