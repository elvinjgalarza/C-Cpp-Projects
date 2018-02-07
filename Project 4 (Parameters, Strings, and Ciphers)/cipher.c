// cipher.c -- EE 312 Project 4

/* Student information for project:
 *
 *
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin J. Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 0
 */


#include <stdio.h>
#include <string.h>

int MAX_ROWS = 6;

// Explains program and encryption
void intro(void){
    printf("This program demonstrates a transposition cipher.\n");
    printf("A cipher is an algorithm to encrypt or decrypt a message.\n\n");
    printf("This program will demonstrate encrypting a message with\n");
    printf("a columnar transposition cipher both with and without\n");
    printf("padding characters. The program will then decrypt a message\n");
    printf("assuming it was encrypted with a columnar transposition cipher\n");
    printf("with padding.\n");
    printf("\n");
    printf("A demonstration of encrypting with a columnar transposition cipher:\n\n");
    printf("Enter the message to encrypt: ");
    return;
}

// Gets length of clear text message from user
// char* str is the same as str[]
// Also REMOVES new line char '\n' from string
int getLength(char* str){
    int len = 0;
    len  = strlen(str)-1;
    str[len] = '\0';

    return len;
}

// Gets required 'columns' to figure out the encryption method
// Turns out we'll be one less required 'column' short if we get a fraction
// from the equation 'columns' = string length/maximum rows,
// so the code accounts for that
int getColumns(int rows, int length){
    int col = 0;
    if(length % rows == 0){
        col = length/rows;
    }
    else{
        col = (length/rows)+1;
    }
    return col;
}

// Encrypts nonpadded clear text message
// accounts for no padding encryption by going to next row for columns-1
// after the row with the str[last element] has been reached
void encryptNoPad(char* str, int rows, int columns, int length){
    char encrypted[80] = {'\0'};
    char* p = encrypted;
    int flag = 0, j = 0, k = 0, m = 0, len = length;
    // do encryption method MAX_ROWS times
    for(int n = 0; n <= rows; n++) {
        //go to next row after columns times
        for (int i = 1; i <= columns; i++) {
            encrypted[k] = str[j];
            len--;
            // if len (length of string) is 0, then we've encrypted each element and are done
            if(len == 0){
                printf("Encrypted with %d rows: %s\n", rows, p);
                return;
            }
            // since we have no padding, we must check if we have reached the last element of str
            // in order to encrypt the rows after the last element correctly
            if(j == length-1) {
                flag = 1;
            }
            j = j + rows;
            k++;
            if(flag == 1 && str[j] == '\0'){
                i = columns+1;
            }
        }
        m++;
        j=m;
    }
}

// Adds padding to the clear text message
// Figured out that the number of padding chars to use is = to rows*columns - length
void addPadding(char* str, int rows, int columns, int length){
    int i = length;
    int pad = rows*columns - length;
    if(pad == 0){
        return;
    }
    while(pad != 0){
        str[i] = 'X';
        i++;
        pad--;
    }
    return;
}

// Encrypts the padded message and returns the pointer to the encrypted string
// 'count' ('length' + PADDING) tells us when to stop encrypting
// We know to go to the next row - after completing the row encryption - 'column' amount of times
void encryptPadded(char* str, int rows, int columns, int length){
    char encrypted_p[80] = {'\0'};
    char* p = encrypted_p;
    int j = 0, k = 0, m = 0, pad_count = length + (rows*columns - length);
    printf("Clear text padded for %d rows: %s\n", rows, str);
    // do encryption method MAX_ROWS times
    for(int n = 0; n <= rows; n++) {
        //go to next row after columns times
        for (int i = 1; i <= columns; i++) {
            encrypted_p[k] = str[j];
            pad_count--;
            // the last padding should be the last element in the encryption, so once all
            // padding has been accounted for is when we can finish
            if(pad_count == 0){
                printf("Encrypted with %d rows: %s\n", rows, p);
                return;
            }
            j = j + rows;
            k++;
        }
        m++;
        j=m;
    }
}

// Explains decryption
void outro(void){
    printf("\n");
    printf("A demonstration of decrypting with a columnar transposition cipher.\n");
    printf("If the length of the message is not a multiple of the number of rows\n");
    printf("it will be padded which may throw off the decryption.\n\n");
}

void decrypt(char* d_str, int rows, int columns_d, int length_d){
    char decrypted[80] = {'\0'};
    char* d = decrypted;
    int j = 0, k = 0, m = 0, pad_count = length_d + (rows*columns_d - length_d);
    printf("Encrypted text padded for %d rows: %s\n", rows, d_str);
    // do decryption method columns_d times
    for(int n = 0; n <= columns_d; n++) {
        //go to next row after rows times
        for (int i = 1; i <= rows; i++) {
            decrypted[k] = d_str[j];
            pad_count--;
            // the last padding should be the last element in the encryption, so once all
            // padding has been accounted for is when we can finish
            if(pad_count == 0){
                printf("Decrypted with %d rows: %s\n", rows, d);
                return;
            }
            j = j + columns_d;
            k++;
        }
        m++;
        j=m;
    }
}

int main() {
    char str[80] = {'\0'};
    intro();
    // gets clear text message from user
    fgets(str, 80, stdin);
    printf("\nMessage encrypted with columnar transposition cipher and no padding.\n");
    int length = getLength(str);
    for(int rows = 2; rows  <= MAX_ROWS; rows++) {
        int columns = getColumns(rows, length);
        encryptNoPad(str, rows, columns, length);
    }
    printf("\nMessage encrypted with columnar transposition cipher and padding.\n\n");
    for(int rows = 2; rows  <= MAX_ROWS; rows++) {
        int columns = getColumns(rows, length);
        addPadding(str, rows, columns, length);
        encryptPadded(str, rows, columns, length);
        // clears the string of padding
        for(int i = length; i <= 80; i++){
            str[i] = '\0';
        }
    }
    // decryption phase
    outro();
        char d_str[80];
    printf("Enter the message to decrypt: ");
        fgets(d_str, 80, stdin);
    printf("\nMessage decrypted with a columnar transposition cipher:\n\n");
    int length_d = getLength(d_str);
    for(int rows = 2; rows  <= MAX_ROWS; rows++) {
        int columns_d = getColumns(rows, length_d);
        addPadding(d_str, rows, columns_d, length_d);
        decrypt(d_str, rows, columns_d, length_d);
        // clears the string of padding
        for(int i = length_d; i <= 80; i++){
            d_str[i] = '\0';
        }
    }
    return 0;
}