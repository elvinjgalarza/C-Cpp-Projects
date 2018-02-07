#include<iostream>

#include "Deck.h"
#include "Hand.h"
/* Student information for project:
 *
 * On my honor, Ankith Kandikonda, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Ankith Kandikonda
 * email address: ankithk@utexas.edu
 * UTEID: avk393
 * Section 5 digit ID: 16025
 * Number of slip days used on this assignment.
 */
using namespace std;

void printStartofGame(Hand p1, Hand p2){
    string s1 = p1.toString();
    string s2 = p2.toString();

    cout << "Hand of Player 1: " << endl;
    cout << s1 << endl;
    cout << "Hand of Player 2: " << endl;
    cout << s2 << endl;
}

void updateWarCount(int& warcounter){
    warcounter++;
}

//check to see if a player is out of cards
bool playerLost(Hand p1, Hand p2, int warcount, int round){
    if(p1.isEmpty()==true){
        cout << "Player 1 lost after " << 5000-round << " rounds." << endl;
        cout << "There were " << warcount << " wars" << endl;
        return true;
    }
    else if(p2.isEmpty()== true){
        cout << "Player 2 lost after " << 5000-round << " rounds." << endl;
        cout << "There were " << warcount << " wars." << endl;
        return true;
    }

    return false;
}

//function to calculate war
int war(vector<Card>& h1, vector<Card>& h2, Hand& p1, Hand& p2, int& warcount){
    Card c1;
    Card c2;
    int size1 = h1.size();
    int size2 = h2.size();
    //adding the cards needed for war into a hand object. return 0 if one of the player's run out of cards
    try{
        while(h1.size()!= size1+2){
            c1 = p1.getNext();
            h1.push_back(c1);
        }
    }
    catch (const char *msg){return 0;}

    try {
        while(h2.size()!= size2+2){
            c2 = p2.getNext();
            h2.push_back(c2);
        }
    }
    catch(const char *msg){return 0;}

    //checking if another war needed
    if(c1.getValue()==c2.getValue()){
        updateWarCount(warcount);
        return war(h1,h2,p1,p2,warcount);
    }
    //checking if player 1 won
    else if((c1.getValue() > c2.getValue()) || c1.getValue()==1){
        return 1;
    }
        //checking if player 2 won
    else if((c1.getValue() < c2.getValue()) || c2.getValue()==1){
        return 2;
    }

}

//used to update winning players hand after war is over
void updateHandAfterWar(vector<Card> h1, vector<Card> h2, Hand& player, Card c1, Card c2){
    //adding winning stack to winners hand first
    for (vector<Card>::reverse_iterator it = h1.rbegin();it != h1.rend() ; it++) {
        player.addCard(*it);
    }
    player.addCard(c1);
    //adding losing stack to winner hand after
    for (vector<Card>::reverse_iterator it = h2.rbegin();it != h2.rend() ; it++) {
        player.addCard(*it);
    }
    player.addCard(c2);
}

int main() {
    Deck deck;
    Hand player1;
    Hand player2;
    int rounds = 1;
    int warcounter = 0;

    //setup for the game
    //distributing 26 cards for each player
    deck.shuffle();
    while(deck.getDeckSize() > 1){
        player1.addCard(deck.dealCard());
        player2.addCard(deck.dealCard());

    }
    //displaying player's hands at beginning
    printStartofGame(player1,player2);

    //actual gameplay
    while(rounds <= 5000){
        //checking if either player has lost yet
        bool checkHands = playerLost(player1,player2,warcounter,rounds);
        if(checkHands==true) return 0;
        //comparing player's cards
        Card c1 = player1.getNext();
        Card c2 = player2.getNext();

        //war condtion
        if(c1.getValue() == c2.getValue()){
            vector<Card> h1;
            vector<Card> h2;
            updateWarCount(warcounter);

            int z = war(h1,h2,player1,player2,warcounter);
            //condition if a player ran out of cards
            if(z==0){
                bool checkStatus = playerLost(player1,player2,warcounter,rounds);
                return 0;
            }
                //condition if player 1 won the war
            else if(z==1){
                updateHandAfterWar(h1,h2,player1,c1,c2);
            }
                //condition if player 2 won the war
            else if(z==2) {
                updateHandAfterWar(h2,h1,player2,c2,c1);
            }
        }
        //condition if player1 wins
        else if((c1.getValue() > c2.getValue()) || c1.getValue()==1){
            player1.addCard(c1);
            player1.addCard(c2);
        }
        //condition if player2 wins
        else if((c1.getValue() < c2.getValue()) || c2.getValue()==1){
            player1.addCard(c2);
            player2.addCard(c1);
        }
        rounds++;
    }

    cout << "The game was a draw after 5000 rounds." << endl;
    cout << "There were " << warcounter << " wars." << endl;
    return 0;
}