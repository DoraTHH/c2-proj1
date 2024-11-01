#ifndef DISPLAYCARD_H
#define DISPLAYCARD_H

#include <iostream>
#include <string>
#include <vector>
#include "deckmgmt.h"


void PrintCards(deck* Deck, std::vector<int> *hand, bool bHideHiddenCard);

//string array of ASCII code for the suits
std::string suits[4] = {
    "\u2665", // HEART
    "\u2660", // SPADE
    "\u2666", // DIAMOND
    "\u2663", // CLUB
};

//Gets a value(card value) and returns the appropriate string
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
        return "X"; //X as debug if we somehow get a invalid card value like 14,15...
    }
}

// Prints cards using ASCII symbols. Loops through the hand and prints "ASCII Cards" by getting the right values/suits from the deck.
//Takes a bool bHideHiddenCard to know if we want to hide the second card of the dealers/house hand
void PrintCards(deck* Deck, std::vector<int> *hand, bool bHideHiddenCard) 
{
    
    for (int i = 0; i < hand->size(); i++)
    {
        std::cout << "┌───────┐  ";
    }
    std::cout << "\n";
    for (int i = 0; i < hand->size(); i++)
    {
        if (bHideHiddenCard && i == 1)
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
        if (bHideHiddenCard && i == 1)
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
        if (bHideHiddenCard && i == 1)
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
#endif