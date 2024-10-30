
#include <ctime>
#include <random>
#include <chrono>
#include <algorithm>
#include "DisplayCards.h"
#include "deckmgmt.h"

using namespace std;

int main()
{

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////// this is what gameflow would look like.
    rules();

    deck deck1;
    int printDeck[52];
    vector<int> playerHand;
    vector<int> bankHand;
    int topOfDeck = 0;

    char wantCard;
    generateIndecies(printDeck, 52, 1);

    //Following two lines shuffles the printDeck. Creates a seed based on time and then shuffles the array.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(printDeck, printDeck + 52, std::default_random_engine(seed));

    // for (int i = 0; i < 52; i++) // Used for debugging: to check if printdeck is shuffled correctly
    // {
    //     std::cout << printDeck[i] << "\n";
    // }

    drawCard(printDeck, &playerHand, topOfDeck);
    topOfDeck++;
    do
    {
        drawCard(printDeck, &playerHand, topOfDeck);
        topOfDeck++;
        PrintCards(&deck1, &playerHand, false);
        int handvalue = handValue(playerHand, 0, deck1);
        if (handvalue < 21)
        {
            std::cout << "Do you want to draw another card? (Y/N)" << endl;
            std::cin >> wantCard;
        }
        else if (handvalue == 21)
        {
            std::cout << "You have 21, awating banks turn" << endl;
        }
        else
        {
            std::cout << "The Bank wins!" << endl;
            wantCard = 'n';
        }

    } while (wantCard == 'y');

    // begin bank logic
    // evaluation of winner

    return 0;
}
