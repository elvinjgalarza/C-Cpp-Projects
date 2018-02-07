#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Recursive.c -- EE 312 Project 7

/* Student information for project:
 *
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 0
 *
 */

//Prototypes for helper functions
bool iterateS(char *s, int b, int e);
bool checkPath(int M, int N, int map[M][N], int row, int col);



//Returns the binary representation of a non-negative number n
int getBinary(int n){
    //base case if given value is just zero, then we only return 0
    if(n == 0){
        return 0;
    }
    else{
        return 10 * getBinary(n/2) + n%2;
    }
}



//------------------------------------------------------------------//
//Helper function for isPalindrome, helps iterate through the string
bool iterateS(char *s, int b, int e){
    //Checking one char at time, if ASCII is same, then true
    if(s[b] != s[e]){
        return false;
    }
    //Helps iterate through list, if b == e, then we fall through and know it's a palindrome
    if(b < e+1){
        return iterateS(s, b+1, e-1);
    }
    return true;
}
//Returns true/false if string s is a palindrome
//True if palindrome
//False if not
bool isPalindrome(char *s){
    int len = strlen(s);
    //If there is only one char or no char, then we have a palindrome
    if(len == 1 || len == 0){
        return true;
    }

    return iterateS(s, 0, len-1);
}
//-----------------------------------------------------------------//



//Returns the number of elements in data that are directly
//followed by double of that element.
int nextIsDouble(int data[], int N){
    // checks base cases
    if(N == 0 || N == 1){
        return 0;
    }
    //start from end of array and one before end
    //compare, decrement N in order to iterate through data
    //if false also add 1 in order to return sum of individual
    //pairs to get total pairs
    if(data[N-1] != data[N-2]*2){
        return nextIsDouble(data, N-1);
    }
    else{
        return nextIsDouble(data, N-1) + 1;
    }
}



//-----------------------------------------------------------------//
//Helper function for canFlowOff... just acts as the recursive
//implementation of checking to see if the droplet can flow
//Returns true or false for the initial path it took
bool checkPath(int M, int N, int map[M][N], int row, int col){
    //debugging variable so it shows in debugger
    //int current = map[row][col];
    //Checks northern elevation
    if(map[row][col] > map[row-1][col]){
        checkPath(M, N, map, row-1, col);
    }
    //Checks southern elevation
    if(map[row][col] > map[row+1][col]){
        checkPath(M, N, map, row+1, col);
    }
    //Checks western elevation
    if(map[row][col] > map[row][col-1]){
        checkPath(M, N, map, row, col-1);
    }
    //Checks eastern elevation
    if(map[row][col] > map[row][col+1]){
        checkPath(M, N, map, row, col+1);
    }
    //Eventually it will either reach the border, or stay stuck
    //Return true to canFlowOff if it reaches the border. Else, false.
    if(row == 0 || row == M-1 || row == M-1 || col == N-1){
        return true;
    }
    else{
        return false;
    }
}
//Given a matrix-defined (MxN) generated 2-D map, a value is passed that
//represents a water droplet. If the water droplet can flow off the map,
//i.e. utilizes int elements in the matrix to represent elevation (the
//greater the element, the higher the elevation is), then return true.
//Else, false.
bool canFlowOff(int M, int N, int map[M][N], int row, int col){
    //If drop is currently on the border of the matrix defined map, then we can flow off
    if(row == 0 || row == M-1 || row == M-1 || col == N-1){
        return true;
    }
    //debugging variable so it shows in debugger
    //int current = map[row][col];
    bool north = false,
            south = false,
            west = false,
            east = false;
    //The variable names just represent the initial path it took.
    //Checks northern elevation
    if(map[row][col] > map[row-1][col]){
        north = checkPath(M, N, map, row-1, col);
    }
    //Checks southern elevation
    if(map[row][col] > map[row+1][col]){
        south = checkPath(M, N, map, row+1, col);
    }
    //Checks western elevation
    if(map[row][col] > map[row][col-1]){
        west = checkPath(M, N, map, row, col-1);
    }
    //Checks eastern elevation
    if(map[row][col] > map[row][col+1]){
        east = checkPath(M, N, map, row, col+1);
    }
    //Final check from if modification was necessary
    if(north == true || south == true || west == true || east == true){
        return true;
    }
    else{
        return false;
    }
}
//------------------------------------------------------------------//