#include <stdio.h>

void firstVerse(void);
void secondVerse(void);
void thirdVerse(void);
void fourthVerse(void);
void fifthVerse(void);
void sixthVerse(void);
void seventhVerse(void);
void eighthVerse(void);
void cowToGoat(void);
void goatToDog(void);
void dogToCat(void);
void catToBird(void);
void birdToSpider(void);
void spiderToFly(void);
void lastLines(void);

// Song.c -- EE 312 Project 2

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin J. Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 0
 * Date: Sept. 11, 2017
 * Purpose: This code prints the lyrics of the song 'There Was an Old woman Who Swallowed a Fly'.
 * The object is to focus on program structure; it encourages the coder to have a software design
 * mindset in order to carry it onto future projects.
 */



/************************************************************/
/************************************************************/
/* All main does is cycle through each of the eight verses */
/************************************************************/
/************************************************************/


int main() {
    firstVerse();
    secondVerse();
    thirdVerse();
    fourthVerse();
    fifthVerse();
    sixthVerse();
    seventhVerse();
    eighthVerse();
    return 0;
}


/********************************************************/
/********************************************************/
/* Each verse function prints non-redundant statements and
 * calls functions that contain redundant statements */
/********************************************************/
/********************************************************/


void firstVerse(void){
    printf("There was an old woman who swallowed a fly.\n");
    lastLines();
}
void secondVerse(void){
    printf("There was an old woman who swallowed a spider,\n");
    printf("That wriggled and iggled and jiggled inside her.\n");
    spiderToFly();
}
void thirdVerse(void){
    printf("There was an old woman who swallowed a bird,\n");
    printf("How absurd to swallow a bird.\n");
    birdToSpider();
}
void fourthVerse(void){
    printf("There was an old woman who swallowed a cat,\n");
    printf("Imagine that to swallow a cat.\n");
    catToBird();
}
void fifthVerse(void){
    printf("There was an old woman who swallowed a dog,\n");
    printf("What a hog to swallow a dog.\n");
    dogToCat();
}
void sixthVerse(void){
    printf("There was an old woman who swallowed a goat,\n");
    printf("She just opened her throat to swallow a goat.\n");
    goatToDog();
}
void seventhVerse(void){
    printf("There was an old woman who swallowed a cow,\n");
    printf("I don't know how she swallowed a cow.\n");
    cowToGoat();
}
void eighthVerse(void){
    printf("There was an old woman who swallowed a horse,\n");
    printf("She died of course.\n");
}


/***********************************************************/
/***********************************************************/
/* This code links to all the redundant lines in the song */
/***********************************************************/
/***********************************************************/



void cowToGoat(void){
    printf("She swallowed the cow to catch the goat,\n");
    goatToDog();
}
void goatToDog(void){
    printf("She swallowed the goat to catch the dog,\n");
    dogToCat();
}
void dogToCat(void){
    printf("She swallowed the dog to catch the cat,\n");
    catToBird();
}
void catToBird(void){
    printf("She swallowed the cat to catch the bird,\n");
    birdToSpider();
}
void birdToSpider(void){
    printf("She swallowed the bird to catch the spider,\n");
    spiderToFly();
}
void spiderToFly(void){
    printf("She swallowed the spider to catch the fly,\n");
    lastLines();
}
void lastLines(void){
    printf("I don't know why she swallowed that fly,\n");
    printf("Perhaps she'll die.\n\n");
}
