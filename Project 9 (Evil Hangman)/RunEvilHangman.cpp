#include "EvilHangmanGame.h"
#include <iostream>
#include <sstream>
#include <set>
#include<string>

using namespace std;

// EvilHangmanGame.cpp (or RunEvilHangman.cpp) -- EE 312 Project 9

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
string createDashes1(int wordLength);
void updateKeyword(string& s, char guess, string word);
int numLetter(char input, string str);
bool completeWord(string word);

//Helper function:
//Creates the dashes for the user specified prospective word
string createDashes1(int wordLength){
    string dashes;
    int i = 0;
    while(i != wordLength){
        dashes += "-";
        i++;
    }
    return dashes;
}

//updating keyword displayed to user
void updateKeyword(string& s, char guess, string word){
    for (int i = 0; i < word.length(); ++i) {
        if(word[i] == guess) s[i] = guess;
    }
}
//returning number of letters from guess by user that are in the family
int numLetter(char input, string str){
    int letters = 0, i = 0;
    while(i != str.length()){
        if(str[i] == input){
            letters++;
        }
        i++;
    }
    return letters;
}
//checking if user has won
bool completeWord(string word){
    int i = 0;
    while(i != word.length()){
        if(word[i] == '-'){
            return false;
        }
        i++;
    }
    return true;
}

// argv[]: 0            1            2          3
// ./evilHangman [dictionary] [wordLength] [guesses]
int main(int argc, char* argv[]){
    stringstream ss; //Variable for obtaining user input

    //Obtains word length from command line (user input)
    int wordLength;
    ss << argv[2]; // Obtains word length
    ss >> wordLength; //converts from string to int and stores it
    ss.clear(); // clear the stream

    //Obtains amount of initial guesses from command line (user input)
    int guesses;
    ss << argv[3];
    ss >> guesses;
    ss.clear();


    set<string> family;  //create the set for the word families
    set<string>::iterator familyIt; //create the iterator for the set of word families

    //go to EvilHangmanGame.cpp to create objects
    EvilHangmanGame newGame;

    //exception handler from thrown exceptions in EvilHangmanGame.cpp
    //send dictionary and word length
    try{
        newGame.startGame(argv[1], wordLength);
    } catch(const char* msg) {
        cout << msg << endl;
        return 0;
    }

    //creating "prospective" word to display to user
    string prospectiveWord = createDashes1(wordLength);


    set<char> guessSet; //create the set used for holding the letters that user guessed
    char userLetterInput;
    while(guesses > 0){
        cout << "You have " << guesses << " guesses left\n" <<  "Letters guessed: ";
        //Maintains the set of letters guessed once at least one has been guessed
        if(guessSet.size() > 0){
            //See slide 13 from Lec5ContainersIterators
            //Traverse the set in increasing order
            set<char>::iterator guessedLetterIt = guessSet.begin();
            while(guessedLetterIt != guessSet.end()){
                cout << *guessedLetterIt << " ";
                guessedLetterIt++;
            }
        }
        cout << "\nWord: " << prospectiveWord << endl;
        cout << "Enter guess: ";
        cin >> userLetterInput;  //obtain user's input

/*
        //attempt at handling multiple chars...
        int c = std::cin.peek();
        if(c == -1){
            throw "Invalid entry: Please only type one letter";
        }

*/
        //now go to makeGuess to manipulate user's guess input
        try {
            family = newGame.makeGuess(userLetterInput);
        }
        catch (char e){
            cout << "You have already guessed that letter, try again" << endl << endl;
            continue;
        }
        catch (const char *msg) {
            cout << msg << endl << endl;
            continue;
        }

        //Code for word family set
        familyIt = family.begin(); // set up the iterator


        //obtain number of letters in the word in the family guessed by user
        int numLetters = numLetter(userLetterInput, *familyIt);


        //update displayed word
        updateKeyword(prospectiveWord, userLetterInput, *familyIt);
        guessSet.insert(userLetterInput);

        if(numLetters <= 0){
            cout << "Sorry there are no " << userLetterInput << "'s" << endl;
            guesses--;
            if(guesses > 0){
                cout << endl;
            }
        }
        else if (numLetters == 1){
            cout << "Yes, there is 1 " << userLetterInput << "\n" << endl;
        }
        else{
            cout << "Yes, there are " << numLetters << " " << userLetterInput << "'s" << "\n" << endl;
        }

        //finally check if user has won
        if(completeWord(prospectiveWord)){
            cout << "You win!" << endl;
            cout << "The word was: " << prospectiveWord;
            return 0;
        }
    }
    //If we've finished and no win, then lose.

    cout << "You lose!" << endl;
    cout << "The word was: " << *familyIt << endl;
    return 0;
}