#include<cstdlib>
#include<time.h>
#include "Card.h"

using namespace std;

Card::Card(){
    //Seed the pseudo random generator that rand() uses
    srand((unsigned)time(NULL));
    //Randomly generates value: (0 to 12 inclusive) + 1
    value = (rand() % 13) + 1;
    //Randomly generates suit: 0 to 2 inclusive
    suit = rand() % 4;
}

Card::Card(int suit, int value){
    //Pointer the objects: value and suit
    this->value = value;
    this->suit = suit;
}

//gets card value
int Card::getValue(){
    return value;
}

//gets suit value
int Card::getSuit(){
    return suit;
}

//returns a string representation of the card: value of suit
string Card::toString()const{
    string s = getSuitAsString();
    string v = getValueAsString();
    return v + " of " + s;
}

//Suit:
//Spades - 3, Heart - 2, Diamonds - 1, Clubs - 0
string Card::getSuitAsString() const{
    if(suit == 3){
        return "Spades";
    }
    if(suit == 2){
        return "Hearts";
    }
    if(suit == 1){
        return "Diamonds";
    }
    if(suit == 0){
        return "Clubs";
    }
}
//Value:
//Ace - 1, 2 to 10 - actual value, Jack - 11, Queen - 12, King - 13
string Card::getValueAsString() const {
    if(value == 1){
        return "Ace";
    }
    //Represent 2 to 10
    if(value == 2){
        return "2";
    }
    if(value == 3){
        return "3";
    }
    if(value == 4){
        return "4";
    }
    if(value == 5){
        return "5";
    }
    if(value == 6){
        return "6";
    }
    if(value == 7){
        return "7";
    }
    if(value == 8){
        return "8";
    }
    if(value == 9){
        return "9";
    }
    if(value == 10){
        return "10";
    }
    if(value == 11){
        return "Jack";
    }
    if(value == 12){
        return "Queen";
    }
    if(value == 13){
        return "King";
    }
}

//compares two card suits to check if they're the same
bool Card::sameSuit(Card& other){
    if(suit == other.getSuit()){
        return true;
    }
    else{
        return false;
    }
}

//compares two card values to check if they're the same
bool Card::sameValue(Card& other){
    if(value == other.getValue()){
        return true;
    }
    else{
        return false;
    }
}

//Operator Overload: Checks to make sure if both cards have the same suit AND value
bool operator ==(Card& c1, Card& c2){
    if((c1.getSuit() == c2.getSuit()) && (c1.getValue() == c2.getValue())){
        return true;
    }
    else{
        return false;
    }
}
ostream& operator <<(ostream& output, const Card& c){
    output << c.toString() << endl;
    return output;
}

