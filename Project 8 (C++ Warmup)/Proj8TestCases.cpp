//----------------------------------------------------------------------------//
// StringPlusPlusTester
//----------------------------------------------------------------------------//
// Name: Jake Nimergood
// Date Created: 11/07/2017
// Last Modified: 11/07/2017
// Description: This file is to test the fuctions of StringPlusPlus.
//----------------------------------------------------------------------------//
// Include Statements & Miscellaneous //
//----------------------------------------------------------------------------//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>

#include "StringPlusPlus.h"

using namespace std;

//----------------------------------------------------------------------------//
// Function Prototypes //
//----------------------------------------------------------------------------//

void charToStringTest(void);
void boolToStringTest(void);
void endsWithTest(void);
void startsWithTest(void);
void toLowerCaseTest(void);
void toUpperCaseTest(void);
void equalsIgnoreCaseTest(void);
void doubleToStringTest(void);
void stringToDoubleTest(void);
void stringReplaceTest(void);
void trimTest(void);
void stringJoinTest(void);
void stringSplitTest(void);
void pigLatinfyTest(void);

//----------------------------------------------------------------------------//
// Main //
//----------------------------------------------------------------------------//

int main() {
    charToStringTest();
    boolToStringTest();
    endsWithTest();
    startsWithTest();
    toLowerCaseTest();
    toUpperCaseTest();
    equalsIgnoreCaseTest();
    doubleToStringTest();
    stringToDoubleTest();
    stringReplaceTest();
    trimTest();
    stringJoinTest();
    stringSplitTest();
    //pigLatinfyTest();
}

//----------------------------------------------------------------------------//
// Test Functions //
//----------------------------------------------------------------------------//

void charToStringTest(void) {
    string s1 = charToString('D');
    string s2 = charToString('E');
    string s3 = charToString('j');
    string s4 = charToString('z');
    string s5 = charToString('5');
    string s6 = charToString('9');
    string s7 = charToString('\0');
    // BEGIN //
    cout << "charToStringTest BEGIN" << endl;
    // Case 1 //
    if(s1 == "D") cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(s2 == "E") cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(s3 == "j") cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // Case 4 //
    if(s4 == "z") cout << "Case 4: PASSED" << endl;
    else cout << "Case 4: FAILED" << endl;
    // Case 5 //
    if(s5 == "5") cout << "Case 5: PASSED" << endl;
    else cout << "Case 5: FAILED" << endl;
    // Case 6 //
    if(s6 == "9") cout << "Case 6: PASSED" << endl;
    else cout << "Case 6: FAILED" << endl;
    // Case 7 //
    if(s7 == "") cout << "Case 7: PASSED" << endl;
    else cout << "Case 7: FAILED" << endl;
    // END //
    cout << "charToStringTest END" << endl << endl;
}

void boolToStringTest(void) {
    string s1 = boolToString(0);
    string s2 = boolToString(1);
    // BEGIN //
    cout << "boolToStringTest BEGIN" << endl;
    // Case 1 //
    if(s1 == "false") cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(s2 == "true") cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // END //
    cout << "boolTOStringTest END" << endl << endl;
}

void endsWithTest(void) {
    string s1 = "My name is blank";
    string s2 = "My name is blank ";
    string s3 = "123456789";
    string s4 = "";
    // BEGIN //
    cout << "endsWithTest BEGIN" << endl;
    // Case 1 //
    if(endsWith(s1, 'k') == true) cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(endsWith(s1, 'K') == false) cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(endsWith(s2, ' ') == true) cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // Case 4 //
    if(endsWith(s3, '9') == true) cout << "Case 4: PASSED" << endl;
    else cout << "Case 4: FAILED" << endl;
    // Case 5 //
    if(endsWith(s4, "") == true) cout << "Case 5: PASSED" << endl;
    else cout << "Case 5: FAILED" << endl;
    // Case 6 //
    if(endsWith(s4, "Blah") == false) cout << "Case 6: PASSED" << endl;
    else cout << "Case 6: FAILED" << endl;
    // Case 7 //
    if(endsWith(s3, "123456789") == true) cout << "Case 7: PASSED" << endl;
    else cout << "Case 7: FAILED" << endl;
    // Case 8 //
    if(endsWith(s3, "89") == true) cout << "Case 8: PASSED" << endl;
    else cout << "Case 8: FAILED" << endl;
    // Case 9 //
    if(endsWith(s2, "blank") == false) cout << "Case 9: PASSED" << endl;
    else cout << "Case 9: FAILED" << endl;
    // Case 10 //
    if(endsWith(s1, "blank") == true) cout << "Case 10: PASSED" << endl;
    else cout << "Case 10: FAILED" << endl;
    // END //
    cout << "endsWithTest END" << endl << endl;
}

void startsWithTest(void) {
    string s1 = "My name is blank";
    string s2 = " My name is blank";
    string s3 = "123456789";
    string s4 = "";
    // Begin //
    cout << "startsWithTest BEGIN" << endl;
    // Case 1 //
    if(startsWith(s1, 'm') == false) cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(startsWith(s1, "My n") == true) cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(startsWith(s2, ' ') == true) cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // Case 4 //
    if(startsWith(s2, "My") == false) cout << "Case 4: PASSED" << endl;
    else cout << "Case 4: FAILED" << endl;
    // Case 5 //
    if(startsWith(s3, "123456789") == true) cout << "Case 5: PASSED" << endl;
    else cout << "Case 5: FAILED" << endl;
    // Case 6 //
    if(startsWith(s3, '1') == true) cout << "Case 6: PASSED" << endl;
    else cout << "Case 6: FAILED" << endl;
    // Case 7 //
    if(startsWith(s4, 'm') == false) cout << "Case 7: PASSED" << endl;
    else cout << "Case 7: FAILED" << endl;
    // Case 8 //
    if(startsWith(s4, "") == true) cout << "Case 8: PASSED" << endl;
    else cout << "Case 8: FAILED" << endl;
    // Case 9 //
    if(startsWith(s3, "456") == false) cout << "Case 9: PASSED" << endl;
    else cout << "Case 9: FAILED" << endl;
    // Case 10 //
    if(startsWith(s4, '\0') == true) cout << "Case 10: PASSED" << endl;
    else cout << "Case 10: FAILED" << endl;
    // END //
    cout << "startsWithTest END" << endl << endl;
}

void toLowerCaseTest(void) {
    string s1 = "my name is WHY BOTHER GUY";
    string s2 = "my name is why bother guy";
    string s3 = "CUPHEAD and MUGMAN";
    string s4 = "cuphead and mugman";
    string s5 = "123456789";
    string s6 = "123HELLO456WORLD789";
    string s7 = "123hello456world789";
    // BEGIN //
    cout << "toLowerCaseTest BEGIN" << endl;
    // Case 1 //
    if(toLowerCase(s1) == s2) cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(toLowerCase(s3) == s4) cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(toLowerCase(s2) == s2) cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // Case 4 //
    if(toLowerCase(s4) == s4) cout << "Case 4: PASSED" << endl;
    else cout << "Case 4: FAILED" << endl;
    // Case 5 //
    if(toLowerCase(s5) == s5) cout << "Case 5: PASSED" << endl;
    else cout << "Case 5: FAILED" << endl;
    // Case 6 //
    if(toLowerCase(s6) == s7) cout << "Case 6: PASSED" << endl;
    else cout << "Case 6: FAILED" << endl;
    // Case 7 //
    if(toLowerCase(s7) == s7) cout << "Case 7: PASSED" << endl;
    else cout << "Case 7: FAILED" << endl;
    // END //
    cout << "toLowerCaseTest END" << endl << endl;
}

void toUpperCaseTest(void) {
    string s1 = "my name is WHY BOTHER GUY";
    string s2 = "MY NAME IS WHY BOTHER GUY";
    string s3 = "cuphead and MUGMAN";
    string s4 = "CUPHEAD AND MUGMAN";
    string s5 = "123456789";
    string s6 = "123hello456world789";
    string s7 = "123HELLO456WORLD789";
    // BEGIN //
    cout << "toUpperCaseTest BEGIN" << endl;
    // Case 1 //
    if(toUpperCase(s1) == s2) cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(toUpperCase(s3) == s4) cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(toUpperCase(s2) == s2) cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // Case 4 //
    if(toUpperCase(s4) == s4) cout << "Case 4: PASSED" << endl;
    else cout << "Case 4: FAILED" << endl;
    // Case 5 //
    if(toUpperCase(s5) == s5) cout << "Case 5: PASSED" << endl;
    else cout << "Case 5: FAILED" << endl;
    // Case 6 //
    if(toUpperCase(s6) == s7) cout << "Case 6: PASSED" << endl;
    else cout << "Case 6: FAILED" << endl;
    // Case 7 //
    if(toUpperCase(s7) == s7) cout << "Case 7: PASSED" << endl;
    else cout << "Case 7: FAILED" << endl;
    // END //
    cout << "toUpperCaseTest END" << endl << endl;
}

void equalsIgnoreCaseTest(void) {
    string s1 = "123cuphead456and789mugman!@#";
    string s2 = "123CUPHEAD456AND789MUGMAN!@#";
    // BEGIN //
    cout << "equalsIgnoreCaseTest BEGIN" << endl;
    // Case 1 //
    if(equalsIgnoreCase(s1, s2) == true) cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // END //
    cout << "equalsIgnoreCaseTest END" << endl << endl;
}

void doubleToStringTest(void) {
    double d1 = 1;
    double d2 = 0;
    double d3 = 10.0;
    double d4 = 123456.789123456;
    // BEGIN //
    cout << "doubleToStringTest BEGIN" << endl;
    // Case 1 //
    if(doubleToString(d1, 0) == "1") cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(doubleToString(d1, 4) == "1.0000") cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(doubleToString(d2, 0) == "0") cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // Case 4 //
    if(doubleToString(d2, 2) == "0.00") cout << "Case 4: PASSED" << endl;
    else cout << "Case 4: FAILED" << endl;
    // Case 5 //
    if(doubleToString(d3, 0) == "10") cout << "Case 5: PASSED" << endl;
    else cout << "Case 5: FAILED" << endl;
    // Case 6 //
    if(doubleToString(d3, 3) == "10.000") cout << "Case 6: PASSED" << endl;
    else cout << "Case 6: FAILED" << endl;
    // Case 7 //
    if(doubleToString(d4, 0) == "123457") cout << "Case 7: PASSED" << endl;
    else cout << "Case 7: FAILED" << endl;
    // Case 8 //
    if(doubleToString(d4, 6) == "123456.789123") cout << "Case 8: PASSED" << endl;
    else cout << "Case 8: FAILED" << endl;
    // END //
    cout << "doubleToStringTest END" << endl << endl;
}

void stringToDoubleTest(void) {
    string s1 = "1";
    string s2 = "0.1234";
    string s3 = "123456.789123";
    string s4 = "0";
    double d1 = 1;
    double d2 = 0.1234;
    double d3 = 123456.789123;
    double d4 = 0;
    // BEGIN //
    cout << "stringToDoubleTest BEGIN" << endl;
    // Case 1 //
    if(stringToDouble(s1) == d1) cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(stringToDouble(s2) == d2) cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(stringToDouble(s3) == d3) cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // Case 4 //
    if(stringToDouble(s4) == d4) cout << "Case 4: PASSED" << endl;
    else cout << "Case 4: FAILED" << endl;
    // END //
    cout << "stringToDoubleTest END" << endl << endl;
}

void stringReplaceTest(void) {
    string s1 = "123456";
    string s2 = "Hello";
    string s3 = " World";
    // BEGIN //
    cout << "stringReplaceTest BEGIN" << endl;
    // Case 1 //
    if(stringReplace(s1, "123", s2) == "Hello456") cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(stringReplace(s1, "456", s3) == "123 World") cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(stringReplace(stringReplace(s1, "123", s2), "456", s3) == "Hello World") cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // END //
    cout << "stringReplaceTest END" << endl << endl;
}

void trimTest(void) {
    string s1 = "    The sky is blue.   ";
    string s2 = "Cuphead and Mugman";
    // BEGIN //
    cout << "trimTest BEGIN" << endl;
    // Case 1 //
    if(trim(s1) == "The sky is blue.") cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(trim(s2) == "Cuphead and Mugman") cout << "Case 2: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // END //
    cout << "trimTest END" << endl << endl;
}

void stringJoinTest(void) {
    string s1 = "Jake";
    string s2 = "Is";
    string s3 = "A";
    string s4 = "Cool";
    string s5 = "Fella";
    string s6 = "Cuphead is a superb game";
    string s7 = "with a phenominal art style.";
    string s8 = "I wish I had time to play it.";
    vector<string> v1;
    vector<string> v2;
    v1.push_back(s1);
    v1.push_back(s2);
    v1.push_back(s3);
    v1.push_back(s4);
    v1.push_back(s5);
    v2.push_back(s6);
    v2.push_back(s7);
    v2.push_back(s8);
    // BEGIN //
    cout << "stringJoinTest BEGIN" << endl;
    // Case 1 //
    if(stringJoin(v1, "") == "JakeIsACoolFella") cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(stringJoin(v1, " ") == "Jake Is A Cool Fella") cout << "Case 2: PASSED" << endl;
    else cout << "Case 2: FAILED" << endl;
    // Case 3 //
    if(stringJoin(v2, " ") == (s6 + ' ' + s7 + ' ' + s8)) cout << "Case 3: PASSED" << endl;
    else cout << "Case 3: FAILED" << endl;
    // Case 4 //
    if(stringJoin(v2, "$$$$") == (s6 + "$$$$" + s7 + "$$$$" + s8)) cout << "Case 4: PASSED" << endl;
    else cout << "Case 4: FAILED" << endl;
    // END //
    cout << "stringJoinTest END" << endl << endl;
}

void stringSplitTest(void) {
    string s1 = "Jake";
    string s2 = "Is";
    string s3 = "A";
    string s4 = "Cool";
    string s5 = "Fella";
    string s6 = "Cuphead is a superb game";
    string s7 = "with a phenominal art style.";
    string s8 = "I wish I had time to play it.";
    string str1 = "!!!" + s1 + "!!!" + s2 + "!!!" + s3 + "!!!" + s4 + "!!!" + s5 + "!!!";
    string str2 = s6 + "#" + s7 + "#" + s8;
    vector<string> v1;
    vector<string> v2;
    v1.push_back("");
    v1.push_back(s1);
    v1.push_back(s2);
    v1.push_back(s3);
    v1.push_back(s4);
    v1.push_back(s5);
    v1.push_back("");
    v2.push_back(s6);
    v2.push_back(s7);
    v2.push_back(s8);
    // BEGIN ??
    cout << "stringSplitTest BEGIN" << endl;
    // Case 1 //
    if(stringSplit(str1, "!!!") == v1) cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // Case 2 //
    if(stringSplit(str2, "#") == v2) cout << "Case 1: PASSED" << endl;
    else cout << "Case 1: FAILED" << endl;
    // END //
    cout << "stringSplitTest END" << endl << endl;
}
