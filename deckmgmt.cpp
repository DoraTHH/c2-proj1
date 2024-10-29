#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

void generateIndecies(int input[], int size, int number);

int main () {
   int deckIndecies[52]; //this is the main array that will be used to point to cards in mainDeck
   generateIndecies(deckIndecies, 52, 1); //initializes and shuffles the array

   for (int i = 0; i < 52; i++) { //debug feature, will be deleted
    std::cout << deckIndecies[i] << "\n";
   }
}

void generateIndecies(int input[], int size, int number) { //function that puts values in an array then shuffles said array
    number--; //refers to the number of decks. will be relevant when generating the negative deck
    for (int i = 0; i < size; i++) {
        input[i] = i + (size * number);
    };
    std::random_shuffle(input, input+size);
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