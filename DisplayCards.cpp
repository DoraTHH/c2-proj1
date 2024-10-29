#include <iostream>
#include <string>
#include <vector>

class Card
{
public:
    std::string suit;
    std::string value;
};

// Unicode symbols for card suits
//SPADE = "\u2660";
//HEART = "\u2665";
//DIAMOND = "\u2666";
//CLUB = "\u2663";

void PrintCards(Card mainDeck[], std::vector<int> *hand, bool bIsHouseHand);

int main()
{
    //Create hands
    std::vector<int> playerHand;
    std::vector<int> houseHand;
    // std::vector<Card> deck;

    //Create deck
    Card deck[52];
    std::string suits[4] = {"\u2665", "\u2663", "\u2666", "\u2660"};
    std::string values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deck[(i * 13) + j].value = values[j];
            deck[(i * 13) + j].suit = suits[i];
        }
    }

    //Test add cards to hand
    playerHand.push_back(4);
    playerHand.push_back(5);
    playerHand.push_back(30);
    playerHand.push_back(13);
    playerHand.push_back(12);
    playerHand.push_back(9);

    //Print every card in hand. Set last param to true if hand == houseHand.
    PrintCards(deck, &playerHand, false); 

    return 0;
}


//Prints cards using ASCII symbols.
void PrintCards(Card mainDeck[], std::vector<int> *hand, bool bIsHouseHand) // Watch out for naming conflicts
{
    if(!bIsHouseHand)
    std::cout << "Player hand: " << "\n";
    else
    std::cout << "House hand: " << "\n";

    for (int i = 0; i < hand->size(); i++)
    {
        std::cout << "┌───────┐  ";
    }
    std::cout << "\n";
    for (int i = 0; i < hand->size(); i++)
    {
        if (bIsHouseHand && i == 1)
        {
            std::cout << "│ " << "?" << "     │  ";
        }
        else if (mainDeck[hand->at(i)].value.compare("10") == 0)
        {
            std::cout << "│ " << mainDeck[hand->at(i)].value << "    │  ";
        }
        else
        {
            std::cout << "│ " << mainDeck[hand->at(i)].value << "     │  ";
        }
    }
    std::cout << "\n";
    for (int i = 0; i < hand->size(); i++)
    {
        if (bIsHouseHand && i == 1)
        {
            std::cout << "│   " << "?" << "   │  ";
        }
        else
        {
            std::cout << "│   " << mainDeck[hand->at(i)].suit << "   │  ";
        }
    }
    std::cout << "\n";
    for (int i = 0; i < hand->size(); i++)
    {
        if (bIsHouseHand && i == 1)
        {
            std::cout << "│     " << "?" << " │  ";
        }
        else if (mainDeck[hand->at(i)].value.compare("10") == 0)
        {
            std::cout << "│    " << mainDeck[hand->at(i)].value << " │  ";
        }
        else
        {
            std::cout << "│     " << mainDeck[hand->at(i)].value << " │  ";
        }
    }
    std::cout << "\n";
    for (int i = 0; i < hand->size(); i++)
    {
        std::cout << "└───────┘  ";
    }
    std::cout << "\n";
}