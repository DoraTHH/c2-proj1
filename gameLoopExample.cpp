#include<iostream>
#include"deckmgmt.h"
#include<vector>
#include<stdbool.h>
using namespace std;

int main () {
    srand(time(NULL));
    deck refDeck;
    vector<int> playerHand;
    vector<int> houseHand;
    int mainDeck[52];
    int topOfDeck = 0;

    // game start:
    generateIndecies (mainDeck, 52, 1);
    drawCard (mainDeck, &playerHand, topOfDeck);
    topOfDeck++;
    drawCard (mainDeck, &playerHand, topOfDeck);
    topOfDeck++;

    drawCard (mainDeck, &houseHand, topOfDeck);
    topOfDeck++;
    drawCard (mainDeck, &houseHand, topOfDeck);
    topOfDeck++;


    // main loop:
    bool hit = 1;
    int playerValue = handValue (playerHand, 0, refDeck);
    while (hit == 1) {
        cout << "\nYour hand: ";
        showHand (playerHand, 0, refDeck);
        cout << "\nValue: " << playerValue;
        if (playerValue > 21) {
                cout << "\nYou go bust";
                break;
        };       

        cout << "\nDealer's hand: Hidden card, ";
        showHand (houseHand, 1, refDeck);
        cout << "\nValue: " << handValue (houseHand, 1, refDeck);
        cout << "\nWould you like one more card?\n1: Yes\n0: No ";
        cin >> hit;

        if (hit == 1) {
            drawCard (mainDeck, &playerHand, topOfDeck);
            topOfDeck++;
            playerValue = handValue (playerHand, 0, refDeck);       
        } else {
            break;
        };
        
    };
        // implement bank logic
    hit = 1;
        cout << "\nDealer reveals their hidden card: ";
        int dealerValue = 0;
    while (hit == 1) {
        dealerValue = handValue (houseHand, 0, refDeck);
        showHand (houseHand, 0, refDeck);
        cout << "\nValue: " << dealerValue;

        (dealerValue < 17) ? hit = 1 : hit = 0;
        if (hit == 1) {
            cout << "\nDealer draws a new card: ";
            drawCard (mainDeck, &houseHand, topOfDeck);
            topOfDeck++;
        } else {
            break;
        };
    };
        // determine a winner

    (playerValue > dealerValue && playerValue <= 21 || dealerValue > 21) ? cout << "\nYou win!!" : cout << "\nHouse wins *womp womp*";

        // allow for playing again by wrapping all this in a meta-loop

}