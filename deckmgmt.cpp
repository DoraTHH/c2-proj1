#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>

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

void generateIndecies(int input[], int size, int number);
void drawCard (int deck[], std::vector<int>* hand, int index);
void showHand (std::vector<int> hand, deck refDeck);
void showCard (card input);
void rules ();

int main () {
    int mainDeck[52]; //this is the main array that will be used to point to cards in mainDeck
    generateIndecies(mainDeck, 52, 1); //initializes and shuffles the array
    int topOfDeck = 0; //used to keep track of which cards have been drawn
    deck refDeck; //never used yet completely necessary


    std::vector<int> playerHand;
    std::vector<int> houseHand;

    //example usage of drawCard, this has the player drawing a card from the deck
    drawCard (mainDeck, &playerHand, topOfDeck);
    topOfDeck++;
    drawCard (mainDeck, &playerHand, topOfDeck);
    topOfDeck++;

    //shows the player's hand
    showHand (playerHand, refDeck);

    /*for (int i = 0; i < 52; i++) { //debug feature, will be deleted
        std::cout << mainDeck[i] << "\n";
    }*/
}

void showHand (std::vector<int> hand, deck refDeck) {
    std::cout << "Your hand: ";
    for (int i = 0; i < hand.size(); i++) {
        showCard (refDeck.cards[hand[i]]);
        if (i < hand.size() - 1) { 
            std::cout << ", ";
        };
    }
};


void drawCard (int deck[], std::vector<int>* hand, int index) {
    //move int at deck[index] to hand
    hand->push_back(deck[index]);

};

void generateIndecies(int input[], int size, int number) { //function that puts values in an array then shuffles said array
    number--; //refers to the number of decks. will be relevant when generating the negative deck
    for (int i = 0; i < size; i++) {
        input[i] = i + (size * number);
    };
    std::random_shuffle(input, input+size); //gonna have to figure out how to make this proper random somehow
}; //somehow it just worked the first time i compiled it









void showCard (card input) {
    switch (input.value)
    {
    case 1:
        std::cout << "Ace";
        break;
    case 2:
        std::cout << "Two";
        break;
    case 3:
        std::cout << "Three";
        break;
    case 4:
        std::cout << "Four";
        break;
    case 5:
        std::cout << "Five";
        break;
    case 6:
        std::cout << "Six";
        break;
    case 7:
        std::cout << "Seven";
        break;
    case 8:
        std::cout << "Eight";
        break;
    case 9:
        std::cout << "Nine";
        break;
    case 10:
        std::cout << "Ten";
        break;
    case 11:
        std::cout << "Jack";
        break;
    case 12:
        std::cout << "Queen";
        break;
    case 13:
        std::cout << "King";
        break;
    };

    std::cout << " of ";
    
    switch (input.suit)
    {
    case 1:
        std::cout << "Hearts";
        break;
    case 2:
        std::cout << "Spades";
        break;
    case 3:
        std::cout << "Diamonds";
        break;
    case 4:
        std::cout << "Clubs";
        break;
    
    default:
        break;
    };
};

void rules() {
    std::cout << "Blackjack Rules:\n";
    std::cout << "1. Objective: Get a hand value closer to 21 than the dealer without going over 21.\n";
    std::cout << "2. Card Values:\n";
    std::cout << "   - Number cards (2-10) = face value\n";
    std::cout << "   - Face cards (J, Q, K) = 10 points\n";
    std::cout << "   - Ace = 1 or 11 points\n";
    std::cout << "3. Gameplay:\n";
    std::cout << "   - Players and the dealer get two cards each.\n";
    std::cout << "   - Players can 'hit' (take another card) or 'stand' (keep their current hand).\n";
    std::cout << "   - Players can 'double down' (double the bet, take one more card) or 'split' (if they have two cards of the same value).\n";
    std::cout << "4. Winning:\n";
    std::cout << "   - Bust (over 21) = lose\n";
    std::cout << "   - Closest to 21 without busting wins\n";
    std::cout << "   - Tie (same value as dealer) = push (bet returned)\n";
    std::cout << "5. Dealer Rules:\n";
    std::cout << "   - Dealer hits until reaching at least 17.\n";
    std::cout << "   - Dealer stands on 17 or higher.\n";
}



void deckCreationTest()
{
    deck myDeck;
    for (int i = 0; i < 52; i++) {
        std::cout << "\nsuit: " << myDeck.cards[i].suit << "value: " << myDeck.cards[i].value;
    }
};