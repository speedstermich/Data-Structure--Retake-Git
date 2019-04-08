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

char getWord(FILE *fp, char *buff) {
  int c = 0;
  while ((c = fgetc(fp)) != EOF &&
         !isalpha(c)) { // if file not EOF but is not alphabeth nothing can do
  }

  if (c == EOF) { // if file get End Of File it will stop
    return 0;
  }

  while (isalpha(c)) { // put c to buffer string
    *buff = tolower(c);
    ++buff;
    c = fgetc(fp);
  }
  *buff = 0;
  return 1;
}

int insertWord(struct Node *p, char *w) { // store word to linklist
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

int searchWord(char *w) { // search word and do count
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

int main(int argc, char const *argv[]) {
  struct Node *p;
  char words[MAXWORD];
  FILE *fp;

  if ((fp = fopen("article.txt", "r")) == NULL) {
    fprintf(stderr, "file can't open !\n");
    return -1;
  }

  while (getWord(fp, words))
    if (searchWord(words) == -1) {
      fprintf(stderr, "Wordlist is full\n");
      return -1;
    }

  for (p = Wordlist; p != NULL; p = p->link) {
    printf("%s %d\n", p->word, p->count);
  }

  fclose(fp);
  return 0;
}
