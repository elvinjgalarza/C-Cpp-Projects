#include "EvilHangmanGame.h"
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

/* Student information for project:
 *
 *
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16135
 * Number of slip days used on this assignment: 2
 */

//Protoypes:
string createDashes(int wordLength);
set<string> newDictionary(string file);
map<string, set<string>> makeMap(char userInput, int wordLength, set<string> wordsFamily);
string compareFamily(string familyA, string familyB);

//This file aids in running a C++ version of Evil Hangman.
//In Evil Hangman, the computer tries to cheat the user by postponing picking a word for as long as possible.
//While the user guesses, there technically isn't a set word as the word always changes until it cannot any longer
//or until the user wins/loses.


//Helper function to the helper function makeMap:
//Creates the dashes for the user specified prospective word
string createDashes(int wordLength){
    string dashes;
    int i = 0;
    while(i != wordLength){
        dashes += "-";
        i++;
    }
    return dashes;
}

//Helper function to startGame:
//Convert existing dictionary to all lowercase in order to handle words easier
set<string> newDictionary(string file){
    set<string> lowerDict; //create a new dictionary set (lower case)
    string word;
    ifstream newDictionary;
    //char c;
    int i = 0;
    newDictionary.open(file);

    //extract words from dictionary using
    //getline(istream object from which chars are extracted, string object where extracted is store)
    while(getline(newDictionary, word)){
        //convert dictionary to lowercase
        i = 0;
        while(word[i] != '\0'){
            word[i] = tolower(word[i]);
            //cout << word[i];
            i++;
        }
        //put the newly converted lowercase word into the new dictionary
        lowerDict.insert(word); //
    }
    newDictionary.close();

    return lowerDict;
}

//Helper function to makeGuess:
//Utilizes map data structure to figure out which family set to choose and obtains the size of the set to be used
//This allows us to properly choose a family
map<string, set<string>> makeMap(char userInput, int wordLength, set<string> wordsFamily){
    //
    map<string, set<string>> wordMap;

    //replicates the "prospective" word from RunEvilHangman
    //creates the dashes for user specified-length word
    string dashes = createDashes(wordLength);

    //set up iterator for the family set
    string word, key;
    set<string>::iterator it = wordsFamily.begin();
    while(it != wordsFamily.end()) {
        key = dashes; //duplicate word dashes to have one that can be modified which becomes our key
        word = *it;
        unsigned int j = 0;
        //Now we see if the user input matches a letter in our family
        //We find the position that the input is in the prospective word
        while (word.find(userInput, j) != string::npos) {
            j = word.find(userInput, j); //index of input
            key[j] = 'X';               //creating key for element in list by modifying the prospective word where the user input occurs
            j++;
        }
        set<string> newString;
        //look for the modified duplicate (key); this word is what we don't want
        if (wordMap.find(key) == wordMap.end()) {
            newString.insert(word);
            wordMap[key] = newString;
        }
        else {
            wordMap[key].insert(word);
        }
        it++;
    }
    return wordMap;
}
//find least letters in two families when number of elements are equal

//Helper function to makeGuess:
//Finds which words to use for specific family
string compareFamily(string familyA, string familyB){
    int indexA = 0, indexB = 0;
    unsigned int i = 0, j = 0;

    //find how many same chars user input gave
    while(i < familyA.length()){
        if(familyA[i] == 'X'){
            indexA++;
        }
        i++;
    }
    while(j < familyB.length()){
        if(familyB[j] == 'X'){
            indexB++;
        }
        j++;
    }

    //Case A
    if(indexA < indexB) {
        return familyA;
    }
    if(indexA > indexB){
        return familyB;
    }

    //Case B
    if(indexA == indexB){
        int k = familyA.length() - 1; //pick the rightmost guessed letter
        while(familyA[k] == 'X' && familyB[k] == 'X' && k > 0) {
            k--;
        }
        if(familyA[k] == 'X') {
            return familyA;
        }
        else {
            return familyB;
        }
    }
    return 0;
}

/* Constructs an EvilHangmanGame object. */
EvilHangmanGame::EvilHangmanGame() {

}

/* This function creates the initial word families based on the word length and the input file. */
void EvilHangmanGame::startGame(string dictionaryFile, int wordLength) {
    //If user wants an invalid word length, then throw exception and terminate
    if(wordLength < 2){
        throw "Oops, an exception occurred! Please provide a valid length.";
    }

    currentWordsLength = wordLength;
    currentWords = newDictionary(dictionaryFile);

    //getting rid of all words not equal to word length specified
    //setup the iterator for set of current words available to use
    set<string>::iterator availableWordsIt = currentWords.begin();
    //Remove words that aren't the user's desired length
    while(availableWordsIt != currentWords.end()){
        if((*availableWordsIt).length() == wordLength) {
            availableWordsIt++;
        }
        else {
            availableWordsIt = currentWords.erase(availableWordsIt);
        }
    }

    //If no words in the dictionary, then throw exception and terminate
    if(currentWords.size() == 0){
        throw "Oops, an exception occurred! The dictionary being used does not have any words of your desired word length,";
    }
}

/* makeGuess() takes the user's guess. If the character has been guessed before, a char is thrown.
   Otherwise, the guess is inserted into instance field guesses. Based on the guess, currentWords
   is updated.
*/
//Since we converted our dictionary to lowercase, we must also convert the user input to lowercase
set<string> EvilHangmanGame::makeGuess(char userInput) {
    userInput = tolower(userInput);

    //If the user input is a letter already guessed, throw char exception
    if(guesses.find(userInput) != guesses.end()) {
        throw 'e';
    }
    //checking if input was valid (not a letter)
    else if (isalpha(userInput) == 0){
        throw "Oops, an exception occurred! Invalid input. Please type a letter.";
    }
    //If input is valid
    else{
        guesses.insert(userInput);
    }


    //make the map data structure for families
    map<string, set<string>> familyMap;
    familyMap = makeMap(userInput, currentWordsLength, currentWords);


    //setup the map iterators
    map<string, set<string>>::iterator familyMapIt = familyMap.begin();
    map<string, set<string>>::iterator otherFamilyMapIt = familyMap.begin();

    //Possible family set cases:
    //A) Family sizes are different, so choose largest size
    //B) Family sizes are equal, so choose:
    //        - Choose the group in which the guessed letter does not appear at all.
    //        - If each group contains the guessed letter, choose the one with the fewest letters.
    //        - If this doesn't reduce the possibilities to one family, choose the one with the rightmost guessed letter.
    //        - If there are still multiple possible families, choose the one with the next rightmost letter. Repeat this step until a family is chosen.

    //Establish size of the words in the families being compared
    int otherFamilySize = (otherFamilyMapIt->second).size();
    int familySize = (familyMapIt->second).size();
    //Establish the set of words chosen from family based on user input
    //and the iterator for setting up the current words set
    set<string> chosenWords = otherFamilyMapIt->second;
    set<string>::iterator currentWordsIt = currentWords.begin();

    while(familyMapIt != familyMap.end()) {
        if(familySize == otherFamilySize){
            //Solve for Case A or B mentioned above
            if(compareFamily(otherFamilyMapIt->first, familyMapIt->first) != otherFamilyMapIt->first){
                otherFamilySize = (familyMapIt->second).size();
                otherFamilyMapIt = familyMapIt;
            }
        }
        else if(familySize > otherFamilySize){
            otherFamilySize = (familyMapIt->second).size();
            otherFamilyMapIt = familyMapIt;
        }
        familyMapIt++;
    }

    //Now update current words available to use
    while(currentWordsIt != currentWords.end()){
        if(chosenWords.find(*currentWordsIt) == chosenWords.end()) {
            currentWordsIt = currentWords.erase(currentWordsIt);
        }
        else{
            currentWordsIt++;
        }
    }


    return chosenWords;
}



