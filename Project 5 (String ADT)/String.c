#include "String.h"
#include<stdio.h>
#include<stdlib.h>

// String.c -- EE 312 Project 5

/* Student information for project:
 * *
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin John Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 1
 * Date: October 6, 2017
 */

// The purpose of this assignment is to develop a String ADT in C,
// practice using dynamically allocated memory and structs,
// and practice with arrays and pointers in C

// Summary: Makes a struct string from a regular string
String *makeString(const char *src){
    //Find length... length = capacity
    unsigned int len = 0;
    for(int x = 0; src[x] != '\0'; x++){
        len++;
    }

    // Allocate memory in order to use str
    struct String *str = malloc(sizeof(struct String));
    //Put length into the struct variables
    str->length = len;
    str->capacity = len;
    //Allocate memory for str->data
    str->data = malloc((len+1)*sizeof(src));
    //Copy string data from src into data array
    for(int i=0; i<str->length+1;i++){
        str->data[i] = src[i];
    }
    //Place the NULL into the struct array
    str->data[str->length]='\0';
    return str;
}
// Summary: Duplicates a string into a struct from a different string struct
String *utStrdup(String *s){
    struct String *newStr = malloc(sizeof(struct String));
    newStr->length = s->length;
    newStr->capacity = s->capacity;
    //Allocates memory to account for the NULL
    newStr->data = malloc((s->length+1)*sizeof(s->data));
    //Adds the NULL
    newStr->data[newStr->length] = '\0';
    for(int i = 0; i < s->capacity; i++){
        newStr->data[i] = s->data[i];
    }
    return newStr;
}
// Summary: Frees memory in order to prevent memory leaks
void utStrfree(String *s){
    free(s->data);
    free(s);
}
// Summary: returns updated length of s data
unsigned int utStrlen(String *s){
    return s->length;
}
String *utStrcpy(String *dst, String *src){
    int j = 0;
    for(int i = 0; i < dst->capacity; i++) {
        dst->data[i] = src->data[i];
        j++;
        if(src->length == j){
            j = dst->capacity - src->capacity;
            i = j;
            if(j == 0){
                dst->data[src->length] = '\0';
            }
            while(j != 0){
                dst->data[i] = ' ';
                j--;
                i++;
                if(j == 0){
                    dst->data[i] = '\0';
                }
            }
            return dst;
        }
    }
}
// Summary: Concatenates dst data with suffix data
// len is the updated length of dst
// j is how we access suffix data, we start at the beginning
// i is how we access dst data, we start at the end of the data and tack on
String *utStrcat(String *dst, String *suffix){
    int j = 0;
    unsigned int len = 0;
    for(int x = 0; dst->data[x] != '\0'; x++){
        len++;
    }
    if(len > 0){
        dst->length = len;
    }
    for(int i = dst->length; i < dst->capacity; i++){
        dst->data[i] = suffix->data[j];
        j++;
        len++;
        if(j > suffix->length){
            dst->length = len;
            return dst;
        }
    }
    dst->length = len;
    dst->data[dst->capacity] = '\0';
    return dst;
}
// Summary: Reallocates memory to s in order to gain more memory to later concatenate
String *utStrrealloc(String *s, unsigned int newCapacity){
    if(s->capacity >= newCapacity){
        return s;
    }
    else{
        s->data = realloc(s->data, (newCapacity + 1) * sizeof(char));
        s->capacity = newCapacity;
        return s;
    }
}
void printut(String *s){
    printf("%s", s->data);
}
