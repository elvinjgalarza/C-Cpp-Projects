#ifndef _Poly_h
#define _Poly_h 1

#include<stdbool.h>

struct node {
  int coeff;
  int exp;
  struct node *next;
};

struct polyType {
  struct node *list;  // Pointer to first node (for high-order term)
};
typedef struct polyType *Poly;

Poly makePoly(char *src);
Poly polyCopy(Poly src);
double polyEval(Poly src, double val);
Poly polyAdd(Poly one, Poly two);
Poly polyMult(Poly one, Poly two);
void addTerm(Poly one, int coeff, int two);
int realRoots(Poly src);
char *stringPoly(Poly src);
bool polyEqual(Poly one, Poly two);
void deletePoly(Poly one);

#endif

