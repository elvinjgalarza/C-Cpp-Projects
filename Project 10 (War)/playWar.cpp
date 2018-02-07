#include<iostream>

#include "Deck.h"
#include "Hand.h"
/* Student information for project:
 *
 * On my honor, Elvin, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Elvin Galarza
 * email address: elvinjohngalarza@gmail.com
 * UTEID: ejg2298
 * Section 5 digit ID: 16020
 * Number of slip days used on this assignment.
 *
 */

//This project simulates the card game War. Two players are dealt half the deck each. The players
//place cards and whomever has the largest card value wins. The player first to lose all cards loses.
//If 5000 rounds have passed, then the game results in a draw. In the instance of a tie, a war begins.
//Players place 2 additional cards each (1 face down and 1 face up). The game continues the same way.
//Suit:
//Spades - 3, Heart - 2, Diamonds - 1, Clubs - 0
//Value:
//Ace - 1, 2 to 10 - actual value, Jack - 11, Queen - 12, King - 13

//Protoypes:
void printP1Hand(Hand p1);
void printP2Hand(Hand p2);
bool hasPlayerLost(Hand p1, Hand p2, int rounds, int wars);
int warOccurred(Hand& p1, vector<Card>& t1, Hand& p2, vector<Card>& t2, int wars);

using namespace std;

//Helper functions that utilize the toString for inital hands
void printP1Hand(Hand p1){
    string s = p1.toString();
    cout << "Hand of Player 1: \n";
    cout << s << endl;
}
void printP2Hand(Hand p2){
    string s = p2.toString();
    cout << "Hand of Player 2: \n";
    cout << s << endl;
}

//Helper function that checks if a player has lost, i.e. (player's hand is empty)
bool hasPlayerLost(Hand p1, Hand p2, int rounds, int wars){
    //If player 1 lost
    if(p1.isEmpty() == true){
        cout << "Player 1 lost after " << rounds << " rounds." << endl;
        cout << "There were " << wars << " wars." << endl;
        return true;
    }
    //If player 2 lost
    else if(p2.isEmpty() == true){
        cout << "Player 2 lost after " << rounds << " rounds." << endl;
        cout << "There were " << wars << " wars." << endl;
        return true;
    }
    //If no one has lost yet
    else{
        return false;
    }
}

//Helper function that simulates a war (tie) occurrence
int warOccurred(Hand& p1, vector<Card>& t1, Hand& p2, vector<Card>& t2){
    //Now we have to figure out how many cards should be placed on the table
    Card c1, c2;
    int sizep1 = t1.size(), sizep2 = t2.size();

    //We must take into account that a player can run out of cards during a war, thus ending the game even if they have
    //a chance at winning during war. Once all cards are out of hand, the player loses.
    //Flag = 0 if this is the case
    try{
        while(t1.size() != sizep1 + 2){
            c1 = p1.getNext();
            t1.push_back(c1);
        }
    }
    catch(const char *msg){
        return 3;
    }
    try{
        while(t2.size() != sizep2 + 2){
            c2 = p2.getNext();
            t2.push_back(c2);
        }
    }
    catch(const char *msg){
        return 3;
    }

    //Another war can occur, so we must check again...
    //Flag = 1, if player 1 wins war
    if((c1.getValue() == 1 && c2.getValue() != 1)
       || (c1.getValue() > c2.getValue())) {
        return 1;

    }
    //Flag = 2, if player 2 wins war
    else if((c1.getValue() != 1 && c2.getValue() == 1)
            || (c1.getValue() < c2.getValue())) {
        return 2;
    }
    //Go through warOccurred(..){...} again
    else if (c1.getValue() == c2.getValue()){
        return warOccurred(p1, t1, p2, t2);
    }
}

int main() {
    Deck deck;
    Hand p1hand, p2hand;
    int roundCount = 0, warCount = 0;

    //shuffle deck before playing
    deck.shuffle();
    //deal cards (26 to each) alternate, so cut deck in half
    int deckSize = deck.getDeckSize()/2;
    for(int i = 0; i < deckSize; i++){
        p1hand.addCard(deck.dealCard());
        p2hand.addCard(deck.dealCard());
    }

    //output players' initial hands
    printP1Hand(p1hand);
    cout << endl;
    printP2Hand(p2hand);
    cout << endl;

    //Start playing the game
    while(roundCount < 5000){
        //First check if player lost (their hand is empty)
        bool end = hasPlayerLost(p1hand, p2hand, roundCount, warCount);
        //If player has, indeed, lost, then we end the game. Else fall through
        if(end == true){
            return 0;
        }
        else{
            //If no loss, then inc round
            roundCount++;
        }


        //Get value of top card and also define a table for each player:
        Card p1card = p1hand.getNext();
        Card p2card = p2hand.getNext();



        //If  player 1 has larger card (remember that Ace beats all cards except Ace)
        if((p1card.getValue() == 1 && p2card.getValue() != 1)
            || (p1card.getValue() > p2card.getValue())){
            p1hand.addCard(p1card);
            p1hand.addCard(p2card);
        }
        //If player 2 has larger card(remember that Ace beats all cards except Ace)
        else if((p1card.getValue() != 1 && p2card.getValue() == 1)
                 ||(p1card.getValue() < p2card.getValue())){
            p2hand.addCard(p2card);
            p2hand.addCard(p1card);
        }

        //if players have equal cards
        else if(p1card.getValue() == p2card.getValue()){
            warCount++;
            //create the table for each player
            vector<Card> p1table, p2table;


            //originally gonna be hard if i return a vector, cause need to return two vectors
            //opted to make a flag that operates for different cases
            int flag = warOccurred(p1hand, p1table, p2hand, p2table);


            //Add winner's table, then loser's table to the winner
            //If player 1 won round, add p1 hand then p2 hand
            if(flag == 1){
                vector<Card>::reverse_iterator it1 = p1table.rbegin();
                vector<Card>::reverse_iterator it2 = p2table.rbegin();
                while(it1 != p1table.rend()){
                    p1hand.addCard(*it1);
                    it1++;
                }
                p1hand.addCard(p1card);
                while(it2 != p2table.rend()){
                    p2hand.addCard(*it2);
                    it2++;
                }
                p1hand.addCard(p2card);
            }
                //If player 2 won round, add p2 hand then p1 hand
            else if(flag == 2){
                vector<Card>::reverse_iterator it1 = p1table.rbegin();
                vector<Card>::reverse_iterator it2 = p2table.rbegin();
                while(it2 != p2table.rend()){
                    p2hand.addCard(*it2);
                    it2++;
                }
                p2hand.addCard(p2card);
                while(it1 != p1table.rend()){
                    p2hand.addCard(*it1);
                    it1++;
                }
                p2hand.addCard(p1card);
            }
            else if(flag == 3) {
                //If player 1 lsot
                if (p1hand.isEmpty() == true) {
                    cout << "Player 1 lost after " << roundCount << " rounds." << endl;
                    cout << "There were " << warCount << " wars." << endl;
                    return true;
                }
                    //If player 2 lost
                else if (p2hand.isEmpty() == true) {
                    cout << "Player 2 lost after " << roundCount << " rounds." << endl;
                    cout << "There were " << warCount << " wars." << endl;
                    return true;
                }
            }
        }
    }
    //If no one has won yet, then it's a tie
    cout << "The game was a draw after 5000 rounds." << endl;
    cout << "There were " << warCount << " wars." << endl;
    return 0;
}