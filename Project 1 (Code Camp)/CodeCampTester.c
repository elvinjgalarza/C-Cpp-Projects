#include<stdio.h>
#include<stdbool.h>
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int, int);
int reverseInt(int); 

// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 *
 * Name: Elvin John Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 0
 *
 */

int main() {
  
  // test 1, hammingDistance
  int h1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int h2[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int expected = 10;
  int actual = hammingDistance(h1, h2, 10);
  printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 1, hamming distance\n\n");
  else printf("**** FAILED **** test 1, hamming distance\n\n");

  // test 2, hamming distance
  int h3[] = {1, 1, 1, 1, 0, 0, 0, 0, 1, 0};
  int h4[] = {0, -1, 0, 1, 0, 1, 0, 1, 0, 1};
  expected =7;
  actual = hammingDistance(h3, h4, 10);
  printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 2, hamming distance\n\n");
  else printf("**** FAILED **** test 2, hamming distance\n\n");

  // test 3, last digit
  int n1 = 1;
  int n2 = 1;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 3 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 3, last digit\n\n");
  else printf("**** FAILED **** test 3, last digit\n\n");

  // test 4, last digit
  n1 = 10;
  n2 = 1001;
  expected = false;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 4, last digit\n\n");
  else printf("**** FAILED **** test 4, last digit\n\n");


  // test 5, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 5 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 5, sum of multiples of 3 or 5\n\n");
  else printf("**** FAILED **** test 5, sum of multiples of 3 or 5\n\n");

  // test 6, reverse int
  n1 = -10000000;
  expected = -1;
  actual = reverseInt(n1);
  printf("Test 6 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 6, reverse int\n\n");
  else printf("**** FAILED **** test 6, reverse int\n\n");

  // test 7, reverse int
  n1 = 2147483647;
  expected = 0;
  actual = reverseInt(n1); 
  printf("Test 7 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 7, reverse int\n\n");
  else printf("**** FAILED **** test 7, reverse int\n\n");

  // test 8, reverse int
  n1 = -2147483648;
  expected = 0;
  actual = reverseInt(n1); 
  printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 8, reverse int\n");
  else printf("**** FAILED **** test 8, reverse int\n");

}
