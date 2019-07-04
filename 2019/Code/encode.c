#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct encode {
  unsigned char in[95];
  unsigned char out[95];
} que;
struct cricle {
  unsigned char ch;
  struct cricle *next;
};
unsigned char a[100], b[100];
int main() {
  struct cricle *first, *p, *q;
  unsigned char cha;
  char str;
  int i, j, m;
  FILE *in, *out;

  gets(a);

  for (i = 0; i < 100; i++)
    for (j = i + 1; j < 100; j++)
      if (a[i] == a[j])
        a[j] = '\0';

  for (i = 0, j = 0; i < 100; i++)
    if (a[i] != '\0')
      b[j++] = a[i];

  for (i = 0; i < 95; i++) {
    cha = ' ' + i;
    for (j = 0; b[j] != '\0'; j++)
      if (b[j] == cha)
        break;
    if (b[j] == '\0') {
      b[j] = cha;
      b[j + 1] = '\0';
    }
  }

  first = p = (struct cricle *)malloc(sizeof(struct cricle));
  first->ch = b[0];
  for (i = 1; i < 95; i++) {
    p->next = (struct cricle *)malloc(sizeof(struct cricle));
    p = p->next;
    p->ch = b[i];
  }
  p->next = first;
  q = p;
  p = first;

  m = p->ch;
  que.in[0] = p->ch;
  que.out[94] = p->ch;
  q->next = p->next;
  free(p);
  p = q->next;
  i = 1;
  j = 0;
  while (p != p->next) {

    if (i != m) {
      q = p;
      p = p->next;
      i++;
    } else {
      que.out[j++] = p->ch;
      que.in[j] = p->ch;
      m = p->ch;
      q->next = p->next;
      free(p);
      p = q->next;
      i = 1;
    }
  }
  que.out[93] = p->ch;
  que.in[94] = p->ch;

  if ((in = fopen("in.txt", "r")) == NULL)
    return 1;
  if ((out = fopen("in_crpyt.txt", "w")) == NULL)
    return 1;
  str = fgetc(in);
  while (str != EOF) {
    for (i = 0; i < 95; i++)
      if (que.in[i] == str) {
        fprintf(out, "%c", que.out[i]);
        break;
      }
    if (i == 95)
      fprintf(out, "%c", str);
    str = fgetc(in);
  }
  exit(0);
  return 0;
}
