#include<stdio.h>
#include<string.h>
#include "Poly.h"


int main() {

  // test 1, makePoly and stringPoly

  Poly p1, p2, p3, p4, p5;

  p1 = makePoly("3x^2 + 5x + 2");
  p2 = makePoly("-2x + 6");

  //addTerm(p1, 4,2);
  if(strcmp(stringPoly(p1), "3x^2 + 5x + 2") == 0 && strcmp(stringPoly(p2), "-2x + 6") == 0) {
    printf("Test 1 makePoly and stringPoly: passed\n");
  }
  else{
    printf("Test1 makePoly and stringPoly: failed\n");
  }


  // test 2, polyMult
  Poly ans = polyMult(p2, p1);
  if(strcmp(stringPoly(ans), "-6x^3 + 8x^2 + 26x + 12") == 0) {
    printf("Test2 polyMult: passed\n");
  }
  else{
    printf("Test 2 polyMult: failed\n");
  }


  //test3, realRoots
  int rootTest1 = realRoots(p1);
  int rootTest2 = realRoots(p2);
  printf("Root Test 1: %d roots\n", rootTest1);
  if(rootTest1 == 2) {
    printf("Test 3 realRoots: passed\n");
  }
  else{
    printf("Test 3 realRoots: failed\n");
  }

  printf("Root Test 2: %d roots\n", rootTest2);
  if(rootTest2 == 1) {
    printf("Test 3 realRoots: passed\n");
  }
  else{
    printf("Test 3 realRoots: failed\n");
  }
//test4, polyAdd
  p4= makePoly("2x^3 - 5x - 4");
  Poly addTest = polyAdd(p1, p4);
  printf("%s\n", stringPoly(p1));
  printf("%s\n", stringPoly(p4));
  printf("%s\n", stringPoly(addTest));
  if(strcmp(stringPoly(addTest), "2x^3 + 3x^2 - 2") == 0) {
    printf("Test4 polyAdd: passed\n");
  }
  else{
    printf("Test 4 polyAdd: failed\n");
  }

  //test5, polyEval
  double eval= polyEval(p1, 3);
  if(eval == 44) {
    printf("Test 5 polyEval: passed\n");
  }
  else{
    printf("Test 5 polyEval: failed\n");
  }

  //test6, polyEqual
  p3= makePoly("3x^2 + 5x + 2");
  bool equalTest1= polyEqual(p1, p2);
  if(equalTest1 == false) {
    printf("Test 6 polyEqual: passed\n");
  }
  else{
    printf("Test 6 polyEqual: failed\n");
  }

  bool equalTest2= polyEqual(p1, p3);
  if(equalTest2 == true) {
    printf("Test 6 polyEqual: passed\n");
  }
  else{
    printf("Test 6 polyEqual: failed\n");
  }

  //test 7, polyCopy
  p5= polyCopy(p1);
  if(strcmp(stringPoly(p5), stringPoly(p1))==0){
    printf("Test 7 polyCopy: passed\n");
  }
  else{
    printf("Test 7 polyCopy: failed\n");
  }

}
    

  
  

