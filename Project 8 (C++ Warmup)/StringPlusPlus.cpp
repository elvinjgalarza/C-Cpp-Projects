#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>

#include "StringPlusPlus.h"

// StringPlusPlus.cpp -- EE 312 Project 8

/* Student information for project:
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin J. Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID:   ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 0
 */

using namespace std;

/* Converts a char value to the string containing the char. */
string charToString(char c) {
    string s;
    if(c == '\0'){
        s = "";
    }
    else{
        s = c;

    }
    return s;
}

/* Converts bool b to the corresponding string, "true" or "false". */
string boolToString(bool b) {
    string s;
    if(b == true){
        return s = "true";
    }
    else{
        return s = "false";
    }
}

/* Returns true if s ends with suf, false otherwise. */
bool endsWith(string s, string suf) {
    if(suf == ""){
        return true;
    }
    int suf_len = suf.length();
    int s_len = s.length();
    int j = 0;
    for(int i = s_len - suf_len; i < s_len; i++){
        if(s[i] != suf[j]){
            return false;
        }
        j++;
    }
    return true;
}

/* Returns true if s ends with ch, false otherwise. */
bool endsWith(string s, char ch) {
    if(ch == '\0'){
        return true;
    }
    int len = s.length();
    if(s[len-1] == ch){
        return true;
    }
    else{
        return false;
    }
}

/* Returns true if s starts with pref, false otherwise. */
bool startsWith(string s, string pref) {
    if(pref == ""){
        return true;
    }
    int len = pref.length();
    for(int i = 0; i < len; i++){
        if(s[i] != pref[i]){
            return false;
        }
    }
    return true;
}

/* Returns true if s starts with ch, false otherwise. */
bool startsWith(string s, char ch) {
    if(ch == '\0'){
        return true;
    }
    if(s[0] == ch){
        return true;
    }
    else{
        return false;
    }
}

/* Returns true if s1 and s2 are equal if case is ignored, false otherwise. */
bool equalsIgnoreCase(string s1, string s2) {
    string s3 = toLowerCase(s1);
    string s4 = toLowerCase(s2);
    if(s3 == s4){
        return true;
    }
    else {
        return false;
    }
}

/* Converts a floating-point number into the corresponding string form with dig digits after the decimal point. */
string doubleToString(double d, int dig) {

    stringstream stream;
    stream << fixed << setprecision(dig) << d;

    string s = stream.str();
    return s;
}

/* Converts a string into its corresponding double value. */
// pre: s contains a fixed point representation of a double
double stringToDouble(string s) {
    double d = 0;
    int len = s.length() - s.find('.') - 1;
    stringstream(s) >> d >> setprecision(len);
    //cout << d << fixed << setprecision(len) << endl; trying to debug

    return d;
}

/* Concatenates the strings in vector (maintaining their order) into a single string. In the returned string,
   any two string elements from the vector are separated by the given delimiter. */
string stringJoin(const vector<string> & v, string delimiter) {
    string t;
    int len = v.size();
    int i = 0;
    while(len != 0){
        t.append(v[i]);
        i++;
        len--;
        if(len == 0){
            return t;
        }
        t.append(delimiter);
    }
    return t;
}

/* Break apart string str into a list of strings separated by the specified delimiter, and place each of
   those strings in a vector. The order of the strings should not change. */
vector<string> stringSplit(string str, string delim) {
    vector<string> v;
    if(str == "" || str == delim){
        return v;
    }

    string s; //modifiable copy of str
    string temp; //holds the word to be copied to the vector
    s.append(str);
    size_t d = 0; //first index of delim in s

    while(s != ""){
        if(s.find(delim) == string::npos){
            temp = s.substr(0,s.length());
            v.push_back(temp);
            return v;
        }
        d = s.find(delim);
        temp = s.substr(0, d);
        v.push_back(temp);
        s.erase(0, d);
        //edge case if the last element is the delimiter, then push an empty string
        if(s == delim){
            v.push_back("");
            return v;
        }
        s.erase(0, delim.length());
    }

    return v;
}

/* Return a lower case version of string s. */
string toLowerCase(string s) {
    std::string t;
    t.append(s);
    for(int i = 0; i < t.length(); i++){
        if(t[i] >= 'A' && t[i] <= 'Z'){
            t[i] = t[i] + ' ';
        }
    }
    return t;
}

/* Return an upper case version of string s. */
string toUpperCase(string s) {
    std::string t;
    t.append(s);
    for(int i = 0; i < t.length(); i++){
        if(t[i] >= 'a' && t[i] <= 'z'){
            t[i] = t[i] - ' ';
        }
    }
    return t;
}

/* Return a new string which is orig with all occurrences of old replaced with repl. */
string stringReplace(string orig, string old, string repl) {
    string s;
    s.append(orig);
    while(s.find(old) != string::npos){
        s.replace(s.find(old), old.length(), repl);
    }
    return s;
}

/* Returns a new string which is s with all leading and trailing whitespace removed. */
string trim(string s) {
    string t;
    t.append(s);
    int len = t.length();
    while(t[0] == ' ' || t[0] == '\n' || t[0] == '\t'){
        t.erase(0, 1);
    }
    while(t[t.length()-1] == ' ' || t[t.length()-1] == '\n' || t[t.length()-1] == '\t'){
        t.erase(t.length()-1,1);
    }
    return t;
}

/* Return a new string that contains s translated into pig latin. The string may contain blank spaces and
   (possibly one) punctuation symbol at the end of words. There will not be punctuation embedded in words, and there will not be digits.  */
string pigLatinfy(string s) {
    string delim = " ";
    vector<string> v;
    v = stringSplit(s, delim);
    string t;
    string end_char;
    string temp;

    for(int i = 0; i < v.size(); i++){
        t = v[i];

        //for last word in string, delete the punctuation to correctly append the Pig Latin suffix.
        if(i == v.size() - 1){
            end_char = t.substr(t.size()-1, 1);
            //If end_char isn't punctuation, and is a letter then we don't delete.
            //Making end_char empty.
            if((end_char >= "a" && end_char <= "z") || (end_char >= "A" && end_char <= "Z")){
                end_char = "";
            }
                //If end_char is, then we maintain it.
            else{
                end_char = t.substr(t.size()-1, 1);
                t.erase(t.size()-1, 1);            }
            //Code for last word that starts with vowel
            if(t[0] == 'a' || t[0] == 'e' || t[0] == 'i' || t[0] == 'o' || t[0] == 'u' || t[0] == 'y'
               || t[0] == 'A' || t[0] == 'E' || t[0] == 'I' || t[0] == 'O' || t[0] == 'U' || t[0] == 'Y'){
                t.append("yay");
                t.append(end_char);
                v[i] = t;
                string done = stringJoin(v, " ");
                return done;
            }
            //Code for last word that starts with consonant
            else{
                while(t[0] != 'a' && t[0] != 'e' && t[0] != 'i' && t[0] != 'o' && t[0] != 'u' && t[0] != 'y'
                      && t[0] != 'A' && t[0] != 'E' && t[0] != 'I' && t[0] != 'O' && t[0] != 'U' && t[0] != 'Y'){
                    temp = t.substr(0,1);
                    t.erase(0,1);
                    t.append(temp);
                }
                t.append("ay");
                t.append(end_char);
                v[i] = t;
                string done = stringJoin(v, " ");
                return done;
            }
        }
        //If the current char being looked at is a vowel
        if(t[0] == 'a' || t[0] == 'e' || t[0] == 'i' || t[0] == 'o' || t[0] == 'u' || t[0] == 'y'
           || t[0] == 'A' || t[0] == 'E' || t[0] == 'I' || t[0] == 'O' || t[0] == 'U' || t[0] == 'Y'){
            t.append("yay");
            v[i] = t;
        }
            //Code for last word that starts with consonant
        else{
            while(t[0] != 'a' && t[0] != 'e' && t[0] != 'i' && t[0] != 'o' && t[0] != 'u' && t[0] != 'y'
                  && t[0] != 'A' && t[0] != 'E' && t[0] != 'I' && t[0] != 'O' && t[0] != 'U' && t[0] != 'Y'){
                temp = t.substr(0,1);
                t.erase(0,1);
                t.append(temp);
            }
            t.append("ay");
            v[i] = t;
        }

    }

}
