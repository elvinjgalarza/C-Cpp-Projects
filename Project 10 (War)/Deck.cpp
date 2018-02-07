#include<cstdlib>
#include<time.h>

#include "Deck.h"

using namespace std;

//If top is 4, that means that Cards at indexes 0 to 3 have been dealt. The next card is at index 4.
//Constructs the deck in order of Suit and Value:
//Example: Ace of Clubs, 2 of Clubs..., King of Clubs, Ace of Diamonds..., King of Spades
Deck::Deck(){
    //Just set to 0 so that it's not some random undesired number
    top = 0;
    //For loop represents the suits (0 to 3): Clubs, Diamonds, Hearts, Spades
    for(int i = 0; i < 4; i++){
        //For loop represents the number of cards per suit (13 total)
        for(int j = 1; j < 14; j++){
            //Calls the Card method from Card.h to construct the Card and then put it in the deck
            Card card(i, j);
            myDeck.push_back(card);
        }
    }
    //initialize the deck size to a standard deck size to be used later now that we've put elements into it
    //It might not always be 52
    deckSize = myDeck.size();
}

void Deck::shuffle(){
    //generate the seed
    srand(time(NULL));

    int cardIndex, cardIndexx;
    //how many times to shuffle cards around
    for(int i = 0; i < SHUFFLE; i++){
        //generate the indices for random cards
        cardIndex = rand() % deckSize + top;
        cardIndexx = rand() % deckSize + top;
        //simulates shuffle around
        Card tempCard = myDeck[cardIndex];
        myDeck[cardIndex] = myDeck[cardIndexx];
        myDeck[cardIndexx] = tempCard;
    }
}

Card& Deck::dealCard(){
    Card& cd = myDeck[top];
    top++;
    deckSize--;
    return cd;
}

//gets the top
int Deck::getTop(){
    return top;
}

//Gets the size of the deck
int Deck::getDeckSize(){
    return deckSize;
}

string Deck::toString(){
    string d;
    for(int i = top; i < deckSize; i++){
        //can do this since Deck.h includes Card.h
        d = myDeck[i].toString() + "\n";
    }
}




    
	    
