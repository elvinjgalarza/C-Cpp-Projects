#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin John Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 0
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/
int hammingDistance(int aList[], int bList[], int len) {

    // EE 312 Students: put your code here
    int a = 0;
    int b = 0;
    int distance = 0;

    for(len; len !=0; len--){
        if(aList[a] - bList[b] == 0) {
            a++;
            b++;
        } else {
            distance++;
            a++;
            b++;
        }
    }
    return distance;
}

/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2.
   post: return true if x and y have the same last digit, false otherwise.
*/
bool lastDigit(int x, int y) {

    // EE 312 Students: put your code here
    int lastX = 0;
    int lastY = 0;

    // I use abs() to do the absolute value of the given number just in case a test case contains a negative number
    // modulus allows us to get the remainder, which turns out to be the last digit in the given number

    lastX = abs(x) % 10;
    lastY = abs(y) % 10;

    if(lastX - lastY == 0){
        return true;
    }
    else{
        return false;
    }

}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/
int sum3or5Multiples() {

    // EE 312 Students: put your code here
    int sum = 0;
    for(int i = 3; i < 1000; i++){
        float x = i % 3;
        float y = i % 5;
        int tempX = i;
        int tempY = i;

        // if we get a 0, then that means that the target number is a multiple of 3 or 5 (or both)
        if(x == 0 && y != 0) {
            while (tempX != 0 || tempX < 0) {
                tempX = tempX - 1;
                if (tempX == 0) {
                    sum = sum + i;
                }
            }
        }
        //included parameter for when y is a multiple of 5 OR when both x and y have a number that's a multiple of 3 and 5
        if((x != 0 && y == 0) || (x == 0 && y ==0)) {
            while (tempY != 0 || tempY < 0) {
                tempY = tempY - 1;
                if (tempY == 0) {
                    sum = sum + i;
                }
            }
        }
    }
    return sum;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return x with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/
int reverseInt(int x) {

    // EE 312 Students: put your code here
    // printf("Storage size for int : %d \n", sizeof(x));

    /* mod is basically the last digit, len is length of x, y is a placeholder for figuring out the length,
     * rev is the current reversed number, neg is just a negative flag for checking if x was negative prior
     * to being reversed */
    int mod = 0;
    int len = 1;
    int y = 0;
    int rev = 0;
    int neg = 0;

    y = abs(x);
    /* this code finds the length of the int */
    while (y != 1) {
        y = y / 10;
        if (y == 0) {
            break;
        }
        len = len + 1;
    }
    /* if x is negative, I make it temporarily positive in order to make it easier to work with when checking overflow*/
    /* turns out that INT_MIN won't become positive since that in itself will become an overflow, so I hard-coded to account
     * for that*/
    if (x < 0) {
        neg = 1;
        x = -x;
        if (x == INT_MIN){
            x=0;
            return(x);
        }
    }

    /* actual portion of code that reverses the int while checking for overflow*/
    /*originally my code only checked for the last digit of x to figure if overflow would
     * occur, but upon inspection I realized that only covered some overflow but not all
     * possible overflow outcomes */
    /*Overflow is checked by seeing if the current reversed number is within range
     * and predicts what may occur... clever way is to just / 10, instead of checking every digit manually with
     * if statements*/
    for (len; len != 0; len--) {
        mod = x % 10;
        if (rev > INT_MAX / 10 || ((rev == INT_MAX / 10) && (mod > INT_MAX % 10))) {
            x = 0;
            return (x);
        }
        rev = rev * 10 + mod;
        x = x / 10;
    }
    if (neg == 1) {
        x = -rev;
        return (x);
    } else {
        x = rev;
        return (x);
    }
}







