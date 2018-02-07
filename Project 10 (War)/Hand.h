#ifndef _HAND_H
#define _HAND_H
#include<string>
#include<vector>
#include "Card.h"

using namespace std;
class Hand {
 private:
    int size;
    int top;
    vector<Card> myHand;
 public:
    Hand();
    int getSize(); //Returns the amount of cards dealt to hand
    string toString();
    int getTop(); //Returns the top card from hand's dealt cards
    bool isEmpty(); //Checks if the hand is empty and has no cards
    void addCard(Card& c); //adds card (c) to the bottom of the hand's dealt cards
    Card& getNext(); //Removes and returns the top card from the Hand.
                     //getNext also throws a string(a char array) if the Hand is empty
};
#endif
