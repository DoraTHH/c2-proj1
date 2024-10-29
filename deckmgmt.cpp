
#include <iostream>
#include <string.h>

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

int main()
{
    deck myDeck;
    for (int i = 0; i < 52; i++) {
        std::cout << "\nsuit: " << myDeck.cards[i].suit << "value: " << myDeck.cards[i].value;
    }
    return 0;
}