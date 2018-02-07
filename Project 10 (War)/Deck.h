#ifndef _DECK_H
#define _DECK_H

#include<string>
#include<vector>
#include "Card.h"

int const SHUFFLE = 5000; 

using namespace std;

class Deck {
 private:
    vector<Card> myDeck; //represents the deck in the form of a vector
    int top; //represents the top of the deck
    int deckSize; //represents the size of the deck
 public:
    Deck(); //creates the deck
    void shuffle();// shuffles deck
    Card& dealCard(); //deals the cards
    int getTop(); //gets the card at top of the deck
    int getDeckSize(); //gets the size of the deck
    string toString();
};

#endif

