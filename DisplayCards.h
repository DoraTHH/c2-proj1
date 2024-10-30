#include <iostream>
#include <string>
#include <vector>
#include "deckmgmt.h"


void PrintCards(deck* Deck, std::vector<int> *hand, bool bIsHouseHand);
std::string suits[4] = {
    "\u2665", // HEART
    "\u2660", // SPADE
    "\u2666", // DIAMOND
    "\u2663", // CLUB
};

std::string GetValueAsString(int value)
{
    switch (value)
    {
    case 1:
        return "A";
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    case 10:
        return "10";
    case 11:
        return "J";
    case 12:
        return "Q";
    case 13:
        return "K";
    default:
        return "X";
    }
}

// Prints cards using ASCII symbols.
void PrintCards(deck* Deck, std::vector<int> *hand, bool bIsHouseHand) // Watch out for naming conflicts
{
    if (!bIsHouseHand)
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
        else if (Deck->cards[hand->at(i)].value == 10)
        {
            std::cout << "│ " << GetValueAsString(Deck->cards[hand->at(i)].value) << "    │  ";
        }
        else
        {
            std::cout << "│ " << GetValueAsString(Deck->cards[hand->at(i)].value) << "     │  ";
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
            std::cout << "│   " << suits[Deck->cards[hand->at(i)].suit-1] << "   │  ";
        }
    }
    std::cout << "\n";
    for (int i = 0; i < hand->size(); i++)
    {
        if (bIsHouseHand && i == 1)
        {
            std::cout << "│     " << "?" << " │  ";
        }
        else if (Deck->cards[hand->at(i)].value == 10)
        {
            std::cout << "│    " << GetValueAsString(Deck->cards[hand->at(i)].value) << " │  ";
        }
        else
        {
            std::cout << "│     " << GetValueAsString(Deck->cards[hand->at(i)].value) << " │  ";
        }
    }
    std::cout << "\n";
    for (int i = 0; i < hand->size(); i++)
    {
        std::cout << "└───────┘  ";
    }
    std::cout << "\n";
}
