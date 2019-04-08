#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 32
#define MAXSIZE 1024
//#define LETTER 'a'
//#define DIGIT '0'

struct Node {
  char word[MAXWORD];
  int count;
  struct Node *link;
};
struct Node *Wordlist = NULL;

// int getWord (FILE *fp, char w[]);
// char type(int c);
char getWord(FILE *fp, char *buf);
int searchWord(char *w);
int insertWord(struct Node *p, char *w);

int main(int argc, char const *argv[]) {
  struct Node *p;
  char word[MAXWORD];
  FILE *fp;

  if ((fp = fopen("article.txt", "r")) == NULL) {
    fprintf(stderr, "file can't open !\n");
    return -1;
  }

  while (getWord(fp, word))
    if (searchWord(word) == -1) {
      fprintf(stderr, "Wordlist is full\n");
      return -1;
    }

  for (p = Wordlist; p != NULL; p = p->link) {
    printf("%s %d\n", p->word, p->count);
  }

  fclose(fp);
  return 0;
}

char getWord(FILE *fp, char *buf) {
  int c = 0;
  while ((c = fgetc(fp)) != EOF && !isalpha(c)) {
  }
  if (c == EOF) {
    return 0;
  }
  while (isalpha(c)) {
    *buf = tolower(c);
    ++buf;
    c = fgetc(fp);
  }
  *buf = 0;
  return 1;
}

int searchWord(char *w) {
  struct Node *p, *q = NULL;
  for (p = Wordlist; p != NULL; q = p, p = p->link) {
    if (strcmp(w, p->word) < 0)
      break;
    else if (strcmp(w, p->word) == 0) {
      p->count++;
      return 0;
    }
  }
  return insertWord(q, w);
}

int insertWord(struct Node *p, char *w) {
  struct Node *q;

  q = (struct Node *)malloc(sizeof(struct Node));
  if (q == NULL)
    return -1;
  strcpy(q->word, w);
  q->count = 1;
  q->link = NULL;

  if (Wordlist == NULL)
    Wordlist = q;
  else if (p == NULL) {
    q->link = Wordlist;
    Wordlist = q;
  } else {
    q->link = p->link;
    p->link = q;
  }
  return 0;
}
