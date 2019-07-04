#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
  char stcak[MAXSIZE];
  int top;
} Sequence;
typedef struct {
  int data[MAXSIZE];
  int top;
} Operate;

int isEmpty(Sequence *s);
int push(Sequence *s, char c);
int pop(Sequence *s, char *c);
int getTop(Sequence *s, char *c);
void translate(char s1[], char s2[]);
int calculate(char a[]);

int main(void) {
  char str1[MAXSIZE], str2[MAXSIZE];
  int result;
  fgets(str1, 100, stdin);
  translate(str1, str2);
  result = calculate(str2);
  printf("%d\n", result);

  return 0;
}

int isEmpty(Sequence *s) {
  if (-1 == s->top)
    return 1;
  else
    return 0;
}
int push(Sequence *s, char c) {
  if (MAXSIZE == s->top)
    return 0;

  s->top++;
  s->stcak[s->top] = c;
  return 1;
}
int pop(Sequence *s, char *c) {
  if (isEmpty((s)))
    return 0;

  *c = s->stcak[s->top];
  s->top--;
  return 1;
}
int getTop(Sequence *s, char *c) {
  if (isEmpty((s)))
    return 0;

  *c = s->stcak[s->top];
  return 1;
}
void translate(char s1[], char s2[]) {
  Sequence s;
  char ch, e = '\0';
  int i = 0, j = 0;
  s.top = -1;
  ch = s1[i++];
  while (ch != '=') {
    switch (ch) {
    case '(':
      push(&s, ch);
      break;
    case ')':
      while (getTop(&s, &e) && e != '(') {
        pop(&s, &e);
        s2[j++] = e;
      }
      pop(&s, &e);
      break;
    case '+':
    case '-':
      while (!isEmpty(&s) && getTop(&s, &e) && e != '(') {
        pop(&s, &e);
        s2[j++] = e;
      }
      push(&s, ch);
      break;
    case '*':
    case '/':
      while (!isEmpty(&s) && getTop(&s, &e) && ('/' == e || '*' == e)) {
        pop(&s, &e);
        s2[j++] = e;
      }
      push(&s, ch);
      break;
    case ' ':
      break;
    default:
      while (ch >= '0' && ch <= '9') {
        s2[j++] = ch;
        ch = s1[i++];
      }
      i--;
      s2[j++] = ' ';
    }
    ch = s1[i++];
  }
  while (!isEmpty(&s)) {
    pop(&s, &e);
    if (e != ' ')
      s2[j++] = e;
  }
  s2[j] = '\0';
}
int calculate(char a[]) {
  Operate s;
  int i = 0, data, result = 0;
  int x1, x2;
  s.top = -1;
  while (a[i] != '\0') {
    if (a[i] >= '0' && a[i] <= '9') {
      data = 0;
      while (a[i] != ' ') {
        data = data * 10 + a[i] - '0';
        i++;
      }
      s.top++;
      s.data[s.top] = data;
    } else {
      switch (a[i]) {
      case '+':
        x1 = s.data[s.top--];
        x2 = s.data[s.top--];
        result = x1 + x2;
        s.data[++s.top] = result;
        break;
      case '-':
        x1 = s.data[s.top--];
        x2 = s.data[s.top--];
        result = x2 - x1;
        s.data[++s.top] = result;
        break;
      case '*':
        x1 = s.data[s.top--];
        x2 = s.data[s.top--];
        result = x1 * x2;
        s.data[++s.top] = result;
        break;
      case '/':
        x1 = s.data[s.top--];
        x2 = s.data[s.top--];
        result = x2 / x1;
        s.data[++s.top] = result;
        break;
      }
      i++;
    }
  }
  if (s.top != -1)
    result = s.data[s.top--];

  return result;
}
