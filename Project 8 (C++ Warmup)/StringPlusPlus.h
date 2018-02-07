#ifndef _STRINGPLUSPLUS_H
#define _STRINGPLUSPLUS_H

#include<string>
#include<vector>

using namespace std;

string charToString(char);
string boolToString(bool);
bool endsWith(string, string);
bool endsWith(string, char);
bool startsWith(string, string);
bool startsWith(string, char);
bool equalsIgnoreCase(string, string);

string doubleToString(double, int);
double stringToDouble(string);

vector<string> stringSplit(string, string);
string stringJoin(const vector<string>&, string delimiter = "\n");

string toLowerCase(string);
string toUpperCase(string);

string stringReplace(string, string, string);
string trim(string);

string pigLatinfy(string);

#endif
