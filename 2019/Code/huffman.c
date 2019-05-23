#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cc {
  char c;
  int num;
};
struct Huff {
  struct cc ccount;
  struct Huff *left, *right;
  struct Huff *next;
};
struct Huff *head = NULL;
char Huffman[9];
char Code[128][9];

void read(FILE *fp, struct cc ccount[]);
void insertSortLink(struct Huff *p);
void creatList(struct cc ccount[]);
void creatHuffman(void);
void creatCode(struct Huff *p, char code, int level);
void madeZIP(FILE *src, FILE *obj);

int main() {
  FILE *fp, *fq;
  struct cc ccount[128];
  int i;
  for (i = 0; i < 128; i++) {
    ccount[i].c = 0;
    ccount[i].num = 0;
  }

  if ((fp = fopen("input.txt", "r")) == NULL)
    exit(-1);
  if ((fq = fopen("output.txt", "w")) == NULL)
    exit(-1);

  read(fp, ccount);
  creatList(ccount);
  creatHuffman();
  creatCode(head, '0', 0);
  madeZIP(fp, fq);

  return 0;
}

void read(FILE *fp, struct cc ccount[]) {
  char c;
  while ((c = fgetc(fp)) != EOF)
    if (c != '\n') {
      ccount[c].c = c;
      ccount[c].num++;
    }
  ccount[0].c = '\0';
  ccount[0].num = 1;
  return;
}
void insertSortLink(struct Huff *p) {
  struct Huff *q = NULL, *r = NULL;
  if (head == NULL)
    head = p;
  else {
    q = head;
    if (p->ccount.num < q->ccount.num) {
      p->next = q;
      head = p;
    } else {
      while (q != NULL && p->ccount.num >= q->ccount.num) {
        r = q;
        q = q->next;
      }
      p->next = q;
      r->next = p;
    }
  }
  return;
}
void creatList(struct cc ccount[]) {
  int i;
  struct Huff *p;

  for (i = 0; i < 128; i++)
    if (ccount[i].num != 0) {
      p = (struct Huff *)malloc(sizeof(struct Huff));
      p->ccount = ccount[i];
      p->left = p->right = p->next = NULL;
      insertSortLink(p);
    }
  return;
}
void creatHuffman(void) {
  struct Huff *p;
  while (head->next != NULL) {
    p = (struct Huff *)malloc(sizeof(struct Huff));
    p->ccount.num = head->ccount.num + head->next->ccount.num;
    p->left = head;
    p->right = head->next;
    p->next = NULL;
    head = head->next->next;
    insertSortLink(p);
  }
  return;
}
void creatCode(struct Huff *p, char code, int level) {
  if (level != 0)
    Huffman[level - 1] = code;
  if (p->left == NULL && p->right == NULL) {
    Huffman[level] = '\0';
    strcpy(Code[p->ccount.c], Huffman);
  } else {
    creatCode(p->left, '0', level + 1);
    creatCode(p->right, '1', level + 1);
  }
  return;
}
void madeZIP(FILE *src, FILE *obj) {
  unsigned char *pc, hc;
  int c = 0, i = 0;
  fseek(src, 0, SEEK_SET);
  do {
    c = fgetc(src);
    if (c == EOF)
      c = 0;
    for (pc = Code[c]; *pc != '\0'; pc++) {
      hc = (hc << 1) | (*pc - '0');
      i++;
      if (i == 8) {
        fputc(hc, obj);
        printf("%x", hc);
        i = 0;
      }
    }
    if (c == 0 && i != 0) {
      while (i++ < 8)
        hc = (hc << 1);
      fputc(hc, obj);
      printf("%x", hc);
    }
  } while (c);
  return;
}
