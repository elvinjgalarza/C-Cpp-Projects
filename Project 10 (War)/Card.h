#ifndef _CARD_H
#define _CARD_H

#include<ostream>
#include<string>

using namespace std;

const int SPADES = 3;
const int HEARTS = 2;
const int DIAMONDS = 1;
const int CLUBS = 0;

const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

class Card {
 private:
    int suit;
    int value;
 public:
    Card(); // random valid card
    Card(int suit, int value); // construct Card with specified values. Throw int exception if args not valid.
    int getValue();
    int getSuit();
    string toString() const;
    string getSuitAsString() const;
    string getValueAsString() const;
    bool sameSuit(Card& other);
    bool sameValue(Card& other);
};

bool operator ==(Card& c1, Card& c2);
ostream& operator <<(ostream& output, const Card& c);

#endif
    
