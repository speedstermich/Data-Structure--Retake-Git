#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Nodeptr, *LinkList;

void Joseph(int n, int k, int m) {
  LinkList p, r, list = NULL;
  int i;
  p = NULL;
  r = NULL;
  for (i = 1; i <= n; i++) {
    p = (LinkList)malloc(sizeof(Nodeptr)); // request for space
    p->data = i;                           // store i to data
    if (list == NULL)
      list = p;
    else
      r->next = p;
    r = p;
  }
  p->next = list; // create circle list
  p = list;
  for (i = 1; i < k; i++) {
    r = p;
    p = p->next;
  }
  while (p->next != p) {
    for (i = 1; i < m; i++) {
      r = p;
      p = p->next;     // in here p is the first starting node
    }                  // p is m node, r is m -1 node
    r->next = p->next; // delete m node
    // printf("%d\n", p -> data);
    free(p);     // release deleted node
    p = r->next; // p is point to new node
  }
  printf("%d\n", p->data); // output the last number
}

int main(int argc, char const *argv[]) {
  int n, q, m;
  // n = total of element, q = from where start, m = number that will be report

  scanf("%d %d %d", &n, &m, &q);
  Joseph(n, q, m);
  return 0;
}

/*Nodeptr createlist (int n)
{
        Nodeptr p, r, head = NULL;
        int a;
}*/
/*void king(int n, int q, int m)
{
        Nodeptr list, p, r;
        int i;
        list = NULL;
        for (i = 0; i < n; i++)
        {
                r =(Nodeptr)malloc(sizeof(Nodeptr));
                r -> data = i;
                if(list == NULL)
                        list = p = r;
                else{
                        p -> next =r;
                        p = 	p -> next ;
                }
        }
        p -> next = list;
        r = p;
        for (p = list, i = 0; i < q - 1; i++, r = p, p -> next)
        {
                r = p;
                p = p -> next;
        }
        while( p-> next != p)
        {
                        for (i = 0; i < m-1; i++)
                        {
                                r = p;
                                p = p -> next;
                        }
                        r -> next = p  -> next;
                        printf("%d\n", p -> data );
                        free (p);
                        p = r -> next;
        }
        //printf("%d\n", p -> data );
}*/

/* Algorithm from Book page 52 */
