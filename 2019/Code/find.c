#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct family {
  char parent[25];
  char lchild[25];
  char rchild[25];
} famList[300];

struct FT {
  char name[25];
  int generation;
  struct FT *parent;
  struct FT *lchild;
  struct FT *rchild;
};
typedef struct FT famTree;

famTree *root = NULL;
char nochild[] = "NULL";

int read(FILE *fp);
int child(char name[]);
void insertTree(famTree *T, char lchild[], char rchild[]);
famTree *search(famTree *T, char name[]);

int main() {
  FILE *fp;
  int num, i;
  char name1[25], name2[25];
  famTree *p, *q, *r;
  if ((fp = fopen("in.txt", "r")) == NULL)
    exit(-1);

  num = read(fp);

  root = (famTree *)malloc(sizeof(famTree));
  strcpy(root->name, famList[0].parent);
  root->generation = 1;

  r = (famTree *)malloc(sizeof(famTree));
  strcpy(r->name, famList[0].lchild);
  r->generation = 2;
  r->parent = root;
  r->lchild = r->rchild = NULL;
  root->lchild = r;
  if (child(famList[0].rchild)) {
    r = (famTree *)malloc(sizeof(famTree));
    strcpy(r->name, famList[0].rchild);
    r->generation = 2;
    r->parent = root;
    r->lchild = r->rchild = NULL;
    root->rchild = r;
  }

  for (i = 1; i < num; i++) {
    r = search(root, famList[i].parent);
    insertTree(r, famList[i].lchild, famList[i].rchild);
  }

  scanf("%s %s", name1, name2);
  p = search(root, name1);
  q = search(root, name2);
  if (p->generation < q->generation)
    printf("%s %s %d\n", name2, name1, q->generation - p->generation);
  else if (p->generation > q->generation)
    printf("%s %s %d\n", name1, name2, p->generation - q->generation);
  else {
    famTree *pParent, *qParent;
    pParent = p;
    qParent = q;
    while (strcmp(pParent->name, qParent->name) != 0) {
      pParent = pParent->parent;
      qParent = qParent->parent;
    }
    printf("%s %s %d\n", pParent->name, name1,
           p->generation - pParent->generation);
    printf("%s %s %d\n", qParent->name, name2,
           q->generation - qParent->generation);
  }
  return 0;
}

int read(FILE *fp) {
  int n, i;
  fscanf(fp, "%d", &n);
  for (i = 0; i < n; i++)
    fscanf(fp, "%s %s %s", famList[i].parent, famList[i].lchild,
           famList[i].rchild);
  fclose(fp);
  return n;
}
int child(char name[]) {
  if (strcmp(name, nochild) == 0)
    return 0;
  else
    return 1;
}
void insertTree(famTree *T, char lchild[], char rchild[]) {
  famTree *p;
  if (child(lchild)) {
    p = (famTree *)malloc(sizeof(famTree));
    strcpy(p->name, lchild);
    p->generation = T->generation + 1;
    p->lchild = p->rchild = NULL;
    p->parent = T;
    T->lchild = p;
  }

  if (child(rchild)) {
    p = (famTree *)malloc(sizeof(famTree));
    strcpy(p->name, rchild);
    p->generation = T->generation + 1;
    p->lchild = p->rchild = NULL;
    p->parent = T;
    T->rchild = p;
  }

  return;
}
famTree *search(famTree *T, char name[]) {
  famTree *p, *q;
  p = T;
  if (p == NULL)
    return p;
  else if (strcmp(p->name, name) == 0)
    return p;
  else {
    q = search(p->lchild, name);
    if (q == NULL)
      return search(p->rchild, name);
    else
      return q;
  }
}
