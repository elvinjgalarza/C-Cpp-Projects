/*
 * Project1.cpp
 * 
 * Name: Elvin J. Galarza
 * EE312
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <ctype.h> // provides the ability to use the tolower function
#include <string.h> //provides the ability to use strcasecomp function

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */


void compareDict(char dictionary[], char word[]){
    int i = 0;
    int count = 0;
    int compare = 1;
    char dictword[100];
    dictword[count] = dictionary[i];
    while(dictionary[i] != 0) {                           //if we haven't reached the end of the dictionary
        // printf("dictword[i] is: %c and location of [i] is: %d\n", dictword[i], i); // debugging purposes
        i++;
        count++;
        dictword[count] = dictionary[i];
        if (dictionary[i] == '\n') {
            dictword[count+1] = 0;
            compare = strcasecmp(word, dictword);
            count = -1;
        }
        if(compare == 0){                                //we have found a match.. try new article word

            return;
        }
        if (dictionary[i] == 0 && compare != 0) {       //we found a mistake! print it
            printf("%s", word);
            count = 0;
        }
    }

}


void constrWord(char dictionary[], char article[], int word_size, int a){
    char word[100];
    int char_loc = 0;
    int w = 0;
    char_loc = a - word_size;                   //gives us starting location of the array's word

    while(char_loc != 0) {

       /** printf("%c", article[char_loc]); **/ // this is just for debugging purposes

        word[w] = article[char_loc];
        word[w] = tolower(word[w]); //this makes the word all lowercase, so that when we're in compareDict it is easier
        w++;                        //increment the word[w] location to construct the word
        word_size--;                // word_size is our flag now
        char_loc++;                 // increment the location to print next char

        if(word_size == 0){         //if we've completed the word
            word[w] = '\n';            // this allows for the string to be ended!
            word[w+1] = 0;
            // printf("original: %s\n", word);  // this is just for debugging purposes

            compareDict(dictionary, word);

            char_loc = 0;           // this allows us to escape the while loop

        }
    }
}

void spellCheck(char article[], char dictionary[]) {
    int a = 0;
    int word_size = 0;
    int letter_flag = 0;  // 0 means no letter, 1 means yes letter
    /** just code to check if I'm printing out the article correctly
     * for (i = 0 ; i >=0; i++){
        printf("%c", article[i]);
    }
    **/
    while (article[a] != 0) {                           // as long as we haven't reached the end of the article[] array we keep searching
        if ((article[a] >= 'a' && article[a] <= 'z') ||
            (article[a] >= 'A' && article[a] <= 'Z')) { //and if the %c is a letter
            word_size++;                                // we increment the word_size
            letter_flag = 1;
        }
        else {
            letter_flag = 0;
        }
        if((letter_flag == 0 && word_size >= 2)){ // if there isn't another letter to be checked,
                                                // and we have the def. of a word, compare it!
            constrWord(dictionary,article, word_size, a);
            word_size = 0;                      // reset word_size after sending it to compareDict, since we're starting over
        }
        else{
            if(letter_flag == 0 && word_size < 2){ //this allows us to go back to the while letter checking statement
                word_size = 0;                      //but we reset, since we ended our current phase and are NOW looking for a different word
            }
            a++; // increment the "pointer"
        }
    }
    if((letter_flag == 1 && word_size >= 2)){                   // if the article[] didn't end with \n and instead ended with 0,
                                                                // the letter_flag would get stuck at 1
                                                                // this was just quick code to prevent that
        constrWord(dictionary,article, word_size, a);
        word_size = 0;                      // reset word_size after sending it to compareDict, since we're starting over
    }
}
