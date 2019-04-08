#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>

struct node {
  int coef;
  int exp;
  struct node *link;
};

void multi(struct node *node1, struct node *node2, struct node *node_res) {
  node_res->coef = (node1->coef) * (node2->coef);
  node_res->exp = (node1->exp) + (node2->exp);
}

void poly_multi(struct node *poly1, struct node *node2, struct node *poly_res) {
  struct node *polynode_p = poly1, *resnode_p = poly_res;
  for (;;) {
    if (polynode_p->link != NULL) {
      multi(polynode_p, node2, resnode_p);
      resnode_p->link = (struct node *)malloc(sizeof(struct node));
      resnode_p = resnode_p->link;
      polynode_p = polynode_p->link;
    } else {
      multi(polynode_p, node2, resnode_p);
      resnode_p->link = NULL;
      break;
    }
  }
}

struct node *merge_poly(struct node *poly1, struct node *poly2) {
  struct node *poly_res = poly1, *poly1_p_tmp = poly1, *poly2_p_tmp = poly2,
              *poly_res_tmp = poly1;
  if (poly1_p_tmp->exp > poly2_p_tmp->exp) {
    poly_res = poly1;
    poly_res_tmp = poly1;
    poly1_p_tmp = poly1_p_tmp->link;
  } else if (poly1_p_tmp->exp < poly2_p_tmp->exp) {
    poly_res = poly2;
    poly_res_tmp = poly2;
    poly2_p_tmp = poly2_p_tmp->link;
  } else if (poly1_p_tmp->exp == poly2_p_tmp->exp) {
    poly_res = poly1;
    poly1_p_tmp->coef += poly2_p_tmp->coef;
    poly_res_tmp = poly1;
    poly1_p_tmp = poly1_p_tmp->link;
    struct node *tmp = poly2_p_tmp;
    poly2_p_tmp = poly2_p_tmp->link;
    free(tmp);
  }

  while (poly1_p_tmp != NULL && poly2_p_tmp != NULL) {
    if (poly1_p_tmp->exp > poly2_p_tmp->exp) {
      poly_res_tmp->link = poly1_p_tmp;
      poly_res_tmp = poly1_p_tmp;
      poly1_p_tmp = poly1_p_tmp->link;
    } else if (poly1_p_tmp->exp < poly2_p_tmp->exp) {
      poly_res_tmp->link = poly2_p_tmp;
      poly_res_tmp = poly2_p_tmp;
      poly2_p_tmp = poly2_p_tmp->link;
    } else if (poly1_p_tmp->exp == poly2_p_tmp->exp) {
      poly1_p_tmp->coef += poly2_p_tmp->coef;
      poly_res_tmp->link = poly1_p_tmp;
      poly_res_tmp = poly1_p_tmp;
      poly1_p_tmp = poly1_p_tmp->link;

      struct node *tmp = poly2_p_tmp;
      poly2_p_tmp = poly2_p_tmp->link;
      free(tmp);
    }
  }

  poly_res_tmp->link = (poly1_p_tmp != 0) ? poly1_p_tmp : poly2_p_tmp;
  return poly_res;
}

struct node *poly_multi_poly(struct node *poly1, struct node *poly2) {
  struct node *node2_tmp = poly2;
  struct node *poly_p_res = (struct node *)malloc(sizeof(struct node));
  poly_multi(poly1, node2_tmp, poly_p_res);
  struct node *poly_p_tmp = (struct node *)malloc(sizeof(struct node));
  node2_tmp = node2_tmp->link;
  if (node2_tmp != NULL) {
    for (;;) {
      poly_multi(poly1, node2_tmp, poly_p_tmp);
      poly_p_res = merge_poly(poly_p_res, poly_p_tmp);
      if (node2_tmp->link != NULL) {
        poly_p_tmp = (struct node *)malloc(sizeof(struct node));
        node2_tmp = node2_tmp->link;
      } else
        break;
    }
  }
  return poly_p_res;
}

int main() {
  struct node *poly1_head = (struct node *)malloc(sizeof(struct node));
  struct node *poly2_head = (struct node *)malloc(sizeof(struct node));
  struct node *res;
  struct node *node_tmp;
  int coef_tmp, exp_tmp;
  char lf;

  for (node_tmp = poly1_head;;) {
    scanf("%d %d%c", &coef_tmp, &exp_tmp, &lf);
    node_tmp->coef = coef_tmp;
    node_tmp->exp = exp_tmp;

    if (lf != '\n') {
      node_tmp->link = (struct node *)malloc(sizeof(struct node));
      node_tmp = node_tmp->link;
    } else {
      node_tmp->link = NULL;
      break;
    }
  }
  for (node_tmp = poly2_head;;) {
    scanf("%d %d%c", &coef_tmp, &exp_tmp, &lf);
    node_tmp->coef = coef_tmp;
    node_tmp->exp = exp_tmp;

    if (lf != '\n') {
      node_tmp->link = (struct node *)malloc(sizeof(struct node));
      node_tmp = node_tmp->link;
    } else {
      node_tmp->link = NULL;
      break;
    }
  }

  res = poly_multi_poly(poly1_head, poly2_head);
  while (res != NULL) {
    printf("%d %d ", res->coef, res->exp);
    res = res->link;
  }
  return 0;
}
