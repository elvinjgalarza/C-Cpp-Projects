#include "Hand.h"

using namespace std;

Hand::Hand(){
    size = 0;
    top = 0;
}

//Returns the amount of cards dealt to hand
int Hand::getSize(){
    return size;
}

//String representation of cards in hand
string Hand::toString(){
    string ss;
    for(int i = top; i < size; i++){
        ss = ss + myHand[i].toString() + "\n";
    }
    return ss;
}

//Returns the top card from hand's dealt cards
int Hand::getTop(){
    return top;
}


bool Hand::isEmpty(){
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}

void Hand::addCard(Card& c){
    myHand.push_back(c);
    size++;
}

Card& Hand::getNext(){
    if(size == 0){
        throw "Player's hand is empty.\n";
    }
    Card& card = myHand[top];
    top++;
    size--;
    return card;
}
