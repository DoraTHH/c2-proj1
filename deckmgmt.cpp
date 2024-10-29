#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>

void generateIndecies(int input[], int size, int number);
void drawCard (int deck[], std::vector<int>* hand, int index);

int main () {
    int mainDeck[52]; //this is the main array that will be used to point to cards in mainDeck
    generateIndecies(mainDeck, 52, 1); //initializes and shuffles the array
    int topOfDeck = 0; //used to keep track of which cards have been drawn

    std::vector<int> playerHand;
    std::vector<int> houseHand;

    //example usage of drawCard, this has the player drawing a card from the deck
    drawCard (mainDeck, &playerHand, topOfDeck);
    topOfDeck++;


    std::cout << playerHand.at(0);

    for (int i = 0; i < 52; i++) { //debug feature, will be deleted
        std::cout << mainDeck[i] << "\n";
    }
}


void drawCard (int deck[], std::vector<int>* hand, int index) {
    //move int at deck[index] to hand
    hand->push_back(deck[index]);

}

void generateIndecies(int input[], int size, int number) { //function that puts values in an array then shuffles said array
    number--; //refers to the number of decks. will be relevant when generating the negative deck
    for (int i = 0; i < size; i++) {
        input[i] = i + (size * number);
    };
    std::random_shuffle(input, input+size); //gonna have to figure out how to make this proper random somehow
}; //somehow it just worked the first time i compiled it








class card
{
public:
int suit;
int value;
};

class deck {
    public: 
        card cards[52];
        deck () {
            int suits[4] = {1, 2, 3, 4};                                  //these arrays
            int values[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //are completely unnecessary
            
            for(int i = 0; i<4; i++)
            {
                for(int j = 0; j<13; j++)
                {
                    cards[(i*13)+j].value = values[j];
                    cards[(i*13)+j].suit = suits[i];
                }
            }

        }
};

void deckCreationTest()
{
    deck myDeck;
    for (int i = 0; i < 52; i++) {
        std::cout << "\nsuit: " << myDeck.cards[i].suit << "value: " << myDeck.cards[i].value;
    }
};