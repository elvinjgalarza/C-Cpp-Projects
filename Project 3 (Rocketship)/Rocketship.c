#include <stdio.h>

void drawCone(void);
void drawSealant(void);
void drawBodyUpWindows(void);
void drawBodyDownWindows(void);

/*
 *  EE312 Assignment 3.
 *  Date: September 17, 2017
 *  On my honor, Elvin, this programming assignment is my own work.
 *
 *  A program to print out a Rocketship in ASCII art form.
 *
 *  Name: Elvin J. Galarza
 *  email address: elvinjohngalarza@gmail.com
 *  UTEID: ejg2298
 *  Section 5 digit ID: 16135
 *  Number of slip days used on this assignment: 0
 *. Total number of slip days used this semester: 0
 */


/* Output varies on the constant int SIZE, but remains proportional. SIZE = 0 should
 * produce nothing.*/

const int SIZE = 7;
int main() {
    drawCone();
    drawSealant();
    drawBodyUpWindows();
    drawBodyDownWindows();
    drawSealant();
    drawBodyDownWindows();
    drawBodyUpWindows();
    drawSealant();
    drawCone();
    return 0;
}


/* drawCone draws the tip of the rocket and the thrusters of the rocket */

void drawCone(void){
    for(int line = 1; line <= (2*SIZE-1); line++){
        for(int space = 1; space <= (-1*line+2*SIZE); space++){
            printf(" ");
        }
        for(int for_slash = 1; for_slash <= line; for_slash++){
            printf("/");
        }
        printf("**");
        for(int back_slash = 1; back_slash <= line; back_slash++){
            printf("\\");
        }
        for(int space = 1; space <= (-1*line+2*SIZE); space++){
            printf(" ");
        }
        printf("\n");
    }
}

/* drawSealant draws the border or sealant of the rocket that connects
 * the big pieces together*/

void drawSealant(void){
    for(int line = SIZE; line > 0; line = 0){
        printf("+");
        for(int equal_star = 1; equal_star <= (4*SIZE/2); equal_star++){
            printf("=*");
        }
        printf("+\n");
    }
}

/* drawBodyUpWindows draws the portion of the body of the rocket with the windows pointing
 * upwards, so UpWindows = /\ .... do not confuse with the top portion of the body*/

void drawBodyUpWindows(void){
    for(int line = 1; line <= SIZE; line++) {
        printf("|");
        for(int l_dot = 1; l_dot <= (-1*line+SIZE); l_dot++) {
            printf(".");
        }
        for(int window = 1; window <= line; window++){
            printf("/\\");
        }
        for(int m_dot = 1; m_dot <= (-2*line+2*SIZE); m_dot++){
            printf(".");
        }
        for(int window = 1; window <= line; window++){
            printf("/\\");
        }
        for(int r_dot = 1; r_dot <= (-1*line+SIZE); r_dot++) {
            printf(".");
        }
        printf("|");
        printf("\n");
    }
}

/* drawBodyDownWindows draws the portion of the body of the rocket with the windows pointing
 * downwards, so DownWindows = \/ .... do not confuse with the bottom portion of the body*/

void drawBodyDownWindows(void){
    for(int line = 1; line <= SIZE; line++){
        printf("|");
        for(int l_dot = 1; l_dot <= (line-1); l_dot++){
            printf(".");
        }
        for(int window = 1; window <= (-1*line+(SIZE+1)); window++){
            printf("\\/");
        }
        for(int m_dot = 1; m_dot <= (2*line-2); m_dot++){
            printf(".");
        }
        for(int window = 1; window <= (-1*line+(SIZE+1)); window++){
            printf("\\/");
        }
        for(int r_dot = 1; r_dot <= (line-1); r_dot++){
            printf(".");
        }
        printf("|");
        printf("\n");
    }
}