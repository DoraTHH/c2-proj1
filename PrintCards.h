#include <iostream>
#include <vector>
#include <string>

void PrintCards(std::vector<int> *hand, bool bIsHouseHand)
{
    for (int i = 0; i < hand->size(); i++)
    {
        if (bIsHouseHand && i == 1)
        {
            std::cout << "Hidden card.\n"; //This is the dealers second card, which is placed face down
        }
        else
        {
            std::cout << hand->at(i) << "\n";
        }
    }
}