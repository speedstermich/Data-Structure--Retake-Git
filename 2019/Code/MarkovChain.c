#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHASH 1048576

typedef struct HashTable {
  char *prefix[2];
  char **suffix;
  int num;
  unsigned int conflict;
  struct HashTable *next;
} HashTable;

double seed = 997;
char *list[1200000];
char *end = "(end)";
HashTable *Hash[NHASH];

void InsertToHash(char *pre1, char *pre2, char *suf);
HashTable *HashSearch(char *pre1, char *pre2);
void write(int num, int Nmax);
unsigned int HashFirst(char *pre1, char *pre2);
unsigned int HashConflict(char *pre);
double rrand(void);

int main(int argc, char const *argv[]) {

  FILE *input;
  int len = 0, num = 0, maximum, i, j;
  char *book;
  char buffer[105];

  input = fopen("article.txt", "r");
  fseek(input, 0, SEEK_END);
  len = ftell(input);
  fseek(input, 0, SEEK_SET);

  book = (char *)malloc(sizeof(char) * len);
  len = fread(book, sizeof(char), len, input);

  for (i = 0, j = 0; i < len; i++) {
    if (book[i] > 32 && book[i] < 127) {
      j = 0;
      while (book[i] > 32 && book[i] < 127) {
        buffer[j++] = book[i++];
      }
      buffer[j] = '\0';
      list[num] = (char *)malloc(sizeof(buffer));
      strcpy(list[num], buffer);
      num++;
    }
  }
  list[num] = end;
  num++;
  fclose(input);

  scanf("%d\n", &maximum);

  for (i = 0; i < num - 2; i++) {
    InsertToHash(list[i], list[i + 1], list[i + 2]);
  }
  write(num, maximum);
  return 0;
}

void InsertToHash(char *pre1, char *pre2, char *suf) {
  unsigned int addr = HashFirst(pre1, pre2);
  unsigned int conflict = HashConflict(pre2);
  if (!Hash[addr]) {
    Hash[addr] = (HashTable *)malloc(sizeof(HashTable));
    Hash[addr]->prefix[0] = pre1;
    Hash[addr]->prefix[1] = pre2;
    Hash[addr]->next = NULL;
    Hash[addr]->num = 1;
    Hash[addr]->conflict = conflict;
    Hash[addr]->suffix = (char **)malloc(sizeof(char *));
    Hash[addr]->suffix[0] = suf;
  } else {
    HashTable *p, *q;
    p = q = Hash[addr];

    while (1) {
      if (!p) {
        HashTable *s = (HashTable *)malloc(sizeof(HashTable));
        s->prefix[0] = pre1;
        s->prefix[1] = pre2;
        s->next = NULL;
        s->num = 1;
        s->conflict = conflict;
        s->suffix = (char **)malloc(sizeof(char *));
        s->suffix[0] = suf;
        q->next = s;

        return;
      } else if (!strcmp(p->prefix[0], pre1) && !strcmp(p->prefix[1], pre2)) {
        p->num++;
        p->suffix = (char **)realloc(p->suffix, p->num * sizeof(char *));
        p->suffix[p->num - 1] = suf;

        return;
      }
      q = p;
      p = p->next;
    }
  }
}

HashTable *HashSearch(char *pre1, char *pre2) {
  unsigned int addr = HashFirst(pre1, pre2);
  unsigned int conflict = HashConflict(pre2);
  HashTable *p = Hash[addr];

  while (1) {
    if (conflict == p->conflict && !strcmp(p->prefix[0], pre1))
      return p;
    p = p->next;
  }
  return 0;
}

void write(int num, int Nmax) {
  FILE *out;
  char *pre1, *pre2;
  int n;

  out = fopen("markov.txt", "w");

  pre1 = list[0];
  pre2 = list[1];
  fprintf(out, "%s %s ", pre1, pre2);
  Nmax -= 2;

  while (Nmax--) {
    HashTable *p = HashSearch(pre1, pre2);

    if (p->num == 1)
      n = 0;
    else
      n = (int)(rrand() * p->num);

    pre1 = pre2;
    pre2 = p->suffix[n];

    if (pre2 == end)
      break;

    fprintf(out, "%s ", pre2);
  }
  fclose(out);
  return;
}
unsigned int HashFirst(char *pre1, char *pre2) {
  unsigned int hash = 0;

  while (*pre1)
    hash = 131 * hash + *pre1++;
  while (*pre2)
    hash = 131 * hash + *pre2++;

  return hash & (NHASH - 1);
}
unsigned int HashConflict(char *pre) {
  unsigned int hash = 5381;

  while (*pre)
    hash += (hash << 5) + (*pre++);

  return hash & (NHASH - 1);
}
double rrand(void) {
  static double lambda = 3125.0;
  static double m = 34359738337.0;
  double r;
  seed = fmod(lambda * seed, m);
  r = seed / m;

  return r;
}
