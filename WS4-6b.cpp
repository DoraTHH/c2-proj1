#include <iostream>
#include <string.h>

class Card
{
public:
std::string suit;
std::string value;
};

int main()
{
    Card cards[52];
    std::string suits[4] = {"Hearts","Clubs","Diamonds","Spades"};
    std::string values[13] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King"};
    
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<13; j++)
        {
            cards[(i*13)+j].value = values[j];
            cards[(i*13)+j].suit = suits[i];
        }
    }

    for(int i = 0;i<52;i++)
    {
        std::cout << cards[i].suit <<"   " << cards[i].value <<"\n";
    }

    return 0;
}