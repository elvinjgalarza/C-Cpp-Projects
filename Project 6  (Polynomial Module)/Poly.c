#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "Poly.h"

/* Student information for project:
 *
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin J. Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 1
 */

//Makes a backwards linked list starting from the tail of the array
//so that the returned linked-list is correctly represented
//O(N)
Poly createList(int arr[], int terms, struct polyType *headRef){
    Poly newNode = malloc(sizeof(struct polyType));
    for(int i = terms; i >= 0; i = i - 2){
        newNode->list = malloc(sizeof(struct node));
        newNode->list->exp = arr[i];
        newNode->list->coeff = arr[i-1];
        if(i == terms){
            newNode->list->next = NULL;
        }
        else{
            newNode->list->next = headRef->list;
        }
        headRef->list = newNode->list;
    }
    return headRef;
}
//Turns a string represented polynomial into a linked-list represented polynomial
//Returns the linked-list representation of the polynomial
//O(N^2)
Poly makePoly(char *src){
    struct polyType *headRef = malloc(sizeof(struct polyType));
    //Find spaces in the poly string
    int spaces = 0;
    for(int i = 0; src[i] != '\0'; i++){
        if(src[i] == ' '){
            spaces++;
        }
    }
    //Since we know the format of a poly string, we can say that # of spaces = 2*# of terms - 2
    //Therefore, we can get the equation for # of terms to be = to (space+2)/2
    //Now we know that the number of portions that are != " " is = signs + terms;
    int signs = spaces/2;
    int terms = (spaces + 2)/2 + signs;
    char srcDup[strlen(src)+1];
    int coeff, exp;
    char fluff1,fluff2;
    int k = 0; // variable to iterate the array we put the coeff and exp in
    int arr[terms + 1];
    int count = 0;  //if count is odd, then we are in a term... if count is even then we are in a sign
    int sign = 1; // -1 = neg, 1 = pos

    //If empty poly
    if(src[0] == '\0'){
        arr[k] = 0;
        arr[k+1] = 0;
        createList(arr, terms, headRef);
        return headRef;
    }

    //This splits up the poly string into terms and signs, so that it is easier to parse
    strcpy(srcDup, src);
    for(int i = terms; i != 0; i--){
        count++;
        fluff1 = 0;
        fluff2 = 0;

        sscanf(srcDup, "%s", srcDup);
       // printf("%s\n", srcDup);
        if(count%2 == 0 && srcDup[0] == '-'){
            sign = -1;
        }
        else if(count%2 == 0 && srcDup[0] == '+'){
            sign = 1;
        }
        else if(srcDup[0] == 'x' && count%2 != 0){
            coeff = 1;
            sscanf(srcDup, "%c%c%d", &fluff1, &fluff2, &exp);
           // printf("coeff: %d\n", coeff);
           // printf("exp: %d\n", exp);
           // printf("---------\n");
            //printf("fluff1: %c\n", fluff1);
            //printf("fluff2: %c\n", fluff2);
            arr[k] = coeff;
            arr[k+1] = exp;
            k += 2;
        }
        if(srcDup[0] != 'x' && count%2 != 0){
            sscanf(srcDup, "%d%c%c%d", &coeff, &fluff1, &fluff2, &exp);
            coeff = sign*coeff;
            if(fluff1 == 'x' && fluff2 == 0){ //if C
                exp = 1;
            }
            if(fluff1 == 0 && fluff2 == 0){ //if Cx
                exp = 0;
            }
          //  printf("coeff: %d\n", coeff);
          //  printf("exp: %d\n", exp);
          //  printf("---------\n");
            //printf("fluff1: %c\n", fluff1);
            //printf("fluff2: %c\n", fluff2);
            arr[k] = coeff;
            arr[k+1] = exp;
            k += 2;
        }

        //This parses the next term or sign
        char *temp = &srcDup[strlen(srcDup)+1];
        sscanf(temp, "%s", temp);
        for(int j = 0; j < strlen(src); j++){
            srcDup[j] = temp[j];
        }
    }
    createList(arr, terms, headRef);

    return headRef;
}
//Duplicates a polynomial from a given linked-list representation of a polynomial
//Returns the replicated polynomial in a linked-list representation
//O(N)
Poly polyCopy(Poly src){
    Poly newHeadRef = malloc(sizeof(struct polyType));
    struct node *newNode = malloc(sizeof(struct node));

    newHeadRef->list = newNode;

    //make temp point to head of src in order to go through it
    struct node *tmp = src->list;

    //Here is where replication occurs
    while(tmp != NULL){
        newNode->coeff = tmp->coeff;
        newNode->exp = tmp->exp;
        tmp = tmp->next;
        //If reached end, finish
        if(tmp == NULL){
            newNode->next = NULL;
        }
        else{
            newNode->next = malloc(sizeof(struct node));
            newNode = newNode->next;
        }
    }

    //newNode instead of newNode->next because then tail has garbage
    newNode = NULL;

    return newHeadRef;
}
//Evaluates a polynomial when given x
//Returns the number evaluated when x is substituted
//O(N^2)
double polyEval(Poly src, double val){
    double eqtn = 0;
    double power = 1;
    struct node *p = src->list;
    while(p != NULL){
        power = 1;
        for(double i = 0; i < p->exp; i++){
            power = power*val;
        }
        if(p->exp == 0){
            eqtn = eqtn + p->coeff;
            return eqtn;
        }
        eqtn = eqtn + (p->coeff * power);
        p = p->next;
    }
    return eqtn;
}
//Takes two polynomials and adds them together
//Returns a polynomial represented as a linked list with no
//O(N)
Poly polyAdd(Poly one, Poly two){
    struct node *p1 = one->list;
    struct node *p2 = two->list;
    Poly newHeadRef = malloc(sizeof(struct polyType));
    struct node *newNode = malloc(sizeof(struct node));
    int flag = 0;

    newHeadRef->list = newNode;
    while(p1 != NULL && p2 != NULL){
        //If p1 exponent is greater, then store it and move on
        //Since they are not like terms
        if(p1->exp > p2->exp){
            newNode->coeff = p1->coeff;
            newNode->exp = p1->exp;
            p1 = p1->next;
        }
        //same concept
        else if(p1->exp < p2->exp){
            newNode->coeff = p2->coeff;
            newNode->exp = p2->exp;
            p2 = p2->next;
        }
        //but if they're the same (like terms), add them
        else{
            newNode->coeff = p1->coeff + p2->coeff;
            //if they cancel out go to next node
            if(newNode-> coeff == 0){
                p1 = p1->next;
                p2 = p2->next;
                flag = 1;
            }
            else{
                newNode->exp = p1->exp;
                p1 = p1->next;
                p2 = p2->next;
                flag = 0;
            }
        }

        if(p1 == NULL && p2 == NULL){
            return newHeadRef;
        }
        //Create the node
        if(flag == 0){
            newNode->next = malloc(sizeof(struct node));
            newNode = newNode->next;
            newNode->next = NULL;
        }
    }
    return newHeadRef;
}
//Multiplies two linked-list represented polynomials
//Returns the product polynomial as a linked-list
//O(N^2)
Poly polyMult(Poly one, Poly two){

    struct node *p1 = one->list;
    struct node *p2 = two->list;
    Poly newHeadRef = malloc(sizeof(struct polyType));
    struct node *newNode = malloc(sizeof(struct node));
    int tCoeff[101];
    int tExp[101];
    int i=0;
    int len1 = 0;
    int len2 = 0;
    newHeadRef->list = newNode;

    //Find len of the polys
    while(p1 != NULL){
        p1 = p1->next;
        len1++;
    }
    while(p2 != NULL){
        p2 = p2->next;
        len2++;
    }

    //Form the coeff and exp arrays
    p1 = one->list;
    p2 = two->list;

    //If poly1 terms > poly2 terms (affects format of array)
    if(len1 >= len2){
        while(p1 != NULL){
            while(p2 != NULL){
                tCoeff[i] = p1->coeff * p2->coeff;
                tExp[i] = p1->exp + p2->exp;
                p2 = p2->next;
                i++;
            }
            p2 = two->list;
            p1 = p1->next;
        }
    }
    //If poly1 terms < poly2 terms (affects format of array)
    if(len1 < len2){
        while(p2 != NULL){
            while(p1 != NULL){
                tCoeff[i] = p1->coeff * p2->coeff;
                tExp[i] = p1->exp + p2->exp;
                p1 = p1->next;
                i++;
            }
            p1 = one->list;
            p2 = p2->next;
        }
    }

    //Count tells us how many times to go through arrays
    int count = len1+len2-1;
    int j = 0;
    //parse array for node
    while(count != 0){
        newNode->coeff = 0;
        while(tExp[j] == tExp[j+1] && count > 1){
            newNode->coeff = newNode->coeff + tCoeff[j];
            newNode->exp = tExp[j];
            j++;
            while(tExp[j] == tExp[j-1]){
                newNode->coeff = newNode->coeff + tCoeff[j];
                j++;
                count--;
            }
            newNode->next = malloc(sizeof(struct node));
            newNode = newNode->next;
            newNode->coeff = 0;
        }
        while(tExp[j] > tExp[j+1] || count == 1) {
            newNode->coeff = tCoeff[j];
            newNode->exp = tExp[j];
            j++;
            if(count == 1){
                newNode->next = NULL;
                return newHeadRef;
            }
            newNode->next = malloc(sizeof(struct node));
            newNode = newNode->next;
            count--;
        }
        if(tExp[j+1] > tExp[j]){
            count = 1;
        }
    }
}
//appends a monomial into it's respective degree place in a linked-list represented polynomial
//Returns the modified(if changes necessary) linked-list
//O(N)
void addTerm(Poly one, int coeff, int exponent){
    struct node *cur = one->list;
    struct node *prev = NULL;


    if(coeff == 0 || exponent < 0){
        return;
    }

    //I. Make a new head
    if(exponent > cur->exp){
        struct node *newNode = malloc(sizeof(struct node));
        newNode->coeff = coeff;
        newNode->exp = exponent;
        newNode->next = cur;
        one->list = newNode;
        return;
    }
    else{
        // III. Combine node if exp are the same
        if(exponent == cur->exp){
            cur->coeff = coeff + cur->coeff;
            return;
        }
        prev = cur;
        cur = cur->next;
        while(cur != NULL){
            if(exponent < cur->exp){
                prev = cur;
                cur = cur->next;
            }
            // II. Insert in between
            else if(exponent > cur->exp && exponent < prev->exp){
                struct node *newNode = malloc(sizeof(struct node));
                newNode->coeff = coeff;
                newNode->exp = exponent;
                newNode->next = cur;
                prev->next = newNode;
                return;
            }
            // III. Combine node if exp are the same
            else if(exponent == cur->exp){
                cur->coeff = coeff + cur->coeff;
                return;
            }
        }
        //IV. Make a new tail
        if(exponent < prev->exp && cur == NULL){
            struct node *newNode = malloc(sizeof(struct node));
            newNode->coeff = coeff;
            newNode->exp = exponent;
            newNode->next = NULL;
            prev->next = newNode;
            return;
        }
    }
}
//Helper function for realRoots, solves for determinant.
//Returns the number of real roots to the realRoot function
//O(1)
int determinant(int a, int b, int c){
    int D = 0;
    D = b*b - (4*a*c);
    if(D > 0){
        return 2;
    }
    else if(D == 0){
        return 1;
    }
    else{
        return 0;
    }
}
//Returns the number of real roots of a polynomial given in linked-list representation
//O(N)
int realRoots(Poly src){
    struct node *cur = src->list;
    Poly newHeadRef = malloc(sizeof(struct polyType));
    struct node *newNode = malloc(sizeof(struct node));
    newHeadRef->list = newNode;
    int len = 0;
    int num = 0, a = 0, b = 0, c = 0;
    while(cur != NULL) {
        cur = cur->next;
        len++;
    }

    cur = src->list;
    while(cur != NULL){
        if(cur->exp >= 3){
            return -1;
        }
        //We can use the deerminant: D = b^2 - 4ac
        //D > 0: two real roots
        // D = 0: one real root
        // D < 0: no real roots

        //For Ax^2 + Bx + C
        else if(cur->exp == 2 && len == 3){
            a = cur->coeff;
            cur = cur->next;
            b = cur->coeff;
            cur = cur->next;
            c = cur->coeff;
            num = determinant(a, b, c);
            return num;
        }
        //For Ax^2 + Bx OR Ax ^2 + C
        else if(cur->exp == 2 && len == 2){
            a = cur->coeff;
            cur = cur->next;
            //for Ax^2 + Bx
            if(cur->exp == 1){
                b = cur->coeff;
                c = 0;
            }
            //for Ax^2 + C
            else{
                b = 0;
                c = cur->coeff;
            }
            num = determinant(a, b, c);
            return num;
        }
        else if(cur->exp == 2 && len == 1){
            return 1;
        }
        else if(cur->exp == 1){
            return 1;
        }
        else if(cur->exp == 0){
            return -1;
        }
        cur = cur->next;
    }


}
//turns a linked-list polynomial representation into a string representation of the polynomial
//itoa is commented out, as sprintf is the alternative that is recognized by the EE Linux servers
//O(N)
char *stringPoly(Poly src){
    struct node *cur = src->list;

    //Dynamic allocation of return array using calloc
    // assign memory to zero, so I dont have to worry about adding EOS
    char *str = calloc(101, sizeof(char));

    //Find length of list, in order to know when I am done making my string (len = terms in poly)
    int len = 0;
    while(cur != NULL){
        cur=cur->next;
        len++;
    }

    //reset cur pointer to src headRef
    cur = src->list;

    //lazy allocation of coeff and exp array
    //made arrays to utilize the itoa (int to char) function
    //this lets me turn the coeff and exp from ints to chars
    char coeff[101], exp[101] = {'\0'};

    //flag used to signal when I've finished my first coeff
    //used it because loop wouldn't work if no flag signalling
    int flag = 0;
    //this is the first coeff put into the return string that I mentioned
    sprintf(coeff, "%d", cur->coeff);
    //itoa(cur->coeff, coeff, 10);
    strcat(str, coeff);

    int num;
    //loop to parse remaining coeffs and exps
    while(cur != NULL){
        len--;
        //if we're at all coeffs after the first node
        if((cur->coeff < 0) && (flag != 0)){
            //itoa(-1 * cur->coeff, coeff, 10);
            sprintf(coeff, "%d", -1 * cur->coeff);
            atoi(coeff);
            strcat(str, coeff);
        }
        else if((cur->coeff) > 0 && (flag != 0)){
            //itoa(cur->coeff, coeff, 10);
            sprintf(coeff, "%d", cur->coeff);
            strcat(str, coeff);
        }

        //handles exponents of 1 and 0
        if(cur->exp == 1){
            strcat(str, "x ");
        }
        else if(cur->exp == 0 && cur->next){
            strcat(str, " ");
        }
        else if(cur->exp > 1){

            strcat(str,"x^");
            //itoa(cur->exp, exp, 10);
            sprintf(exp, "%d", cur->exp);
            strcat(str, exp);
            strcat(str," ");
        }

        //signals when we've gone through whole linked list
        if(len == 0){
            return str;
        }

        //after we've done coeff and exp for one node, go to next
        cur = cur->next;
        //handles coeff after the first node in order to incorporate the "_+_" or "_-_" signs
        if(cur->coeff < 0){
            strcat(str,"- ");
        }
        else{
            strcat(str,"+ ");
        }
        //increment to make sure we go into the beginning-of-the-loop coeff code
        //that is similar to the outside-loop coeff code
        flag++;
    }
    return str;
}
//Returns true if two polynomials are exactly the same
//Returns false if not
//O(N)
bool polyEqual(Poly one, Poly two){
    struct node *p1 = one->list;
    struct node *p2 = two->list;
    if(p1 == NULL && p2 != NULL){
        return false;
    }
    if(p1 != NULL && p2 == NULL){
        return false;
    }
    while(p1 != NULL && p2 != NULL){
        if((p1->coeff != p2->coeff) || (p1->exp != p2->exp)){
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
//Destroys the polynomial and deallocates all memory associated with it
//O(N)
void deletePoly(Poly one){
    struct node *p = one->list;
    while(p){
        struct node *p1 = p;
        p = p->next;
        free(p1);
    }
}