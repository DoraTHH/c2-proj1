#include<iostream>
#include"deckmgmt.h"
#include<vector>
using namespace std;

int main () {
    srand(time(NULL));
    deck refDeck;
    vector<int> playerHand;
    vector<int> houseHand;
    int mainDeck[52];
    int topOfDeck = 0;

    generateIndecies (mainDeck, 52, 1);
    drawCard (mainDeck, &playerHand, topOfDeck);
    topOfDeck++;
    drawCard (mainDeck, &playerHand, topOfDeck);
    topOfDeck++;

    drawCard (mainDeck, &houseHand, topOfDeck);
    topOfDeck++;
    drawCard (mainDeck, &houseHand, topOfDeck);
    topOfDeck++;

    cout << "\nYour hand: ";
    showHand (playerHand, 0, refDeck);
    cout << "\nValue: " << handValue (playerHand, 0, refDeck);

    cout << "\nDealer's hand: Hidden card, ";
    showHand (houseHand, 1, refDeck);
    cout << "\nValue: " << handValue (houseHand, 1, refDeck);
}