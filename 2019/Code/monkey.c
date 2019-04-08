#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *link;
} LNODE, *LinkList;

void Joseph(int n, int k, int m) {
  LinkList p, r, list = NULL; // start value
  int i;
  p = NULL;
  r = NULL;

  for (i = 1; i <= n; i++) {             // make a circular link list
    p = (LinkList)malloc(sizeof(LNODE)); // create new link
    p->data = i;                         // store i to node data
    if (list == NULL) {                  // if head == NULL or empty
      list = p;                          // head insert p
    } else {
      r->link = p; // create next node
    }
    r = p; // next node value is p
  }

  p->link = list;           // make a circular link list
  p = list;                 // p is connected to head
  for (i = 1; i < k; i++) { // the start point of link list
    r = p;                  //	r is the value
    p = p->link;            // p is the connection
  }

  while (p->link != p) {      // when p link not back to p
    for (i = 1; i < m; i++) { // search for number want to remove
      r = p;                  //	r is the value
      p = p->link;            // p is the connection
    }
    r->link = p->link; // remove p

    free(p);     // release p
    p = r->link; // and p is r link
  }

  printf("%d\n", p->data); // to print out data
}

int main(int argc, char const *argv[]) {
  int n, q, m; // n = total of element, q = from where to start, m = number that
               // remove
  scanf("%d %d %d", &n, &m, &q);
  Joseph(n, q, m);
  return 0;
}
