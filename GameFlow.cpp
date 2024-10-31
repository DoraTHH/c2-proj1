
#include <ctime>
#include <random>
#include <chrono>
#include <algorithm>
#include "DisplayCards.h"
#include "deckmgmt.h"
#include <cstdlib> /*For rand() and srand()*/
#include <ctime>   /*For time*/

using namespace std;

int drawSubDeck(int array[]); // Pekar på ett random index i en array

int main()
{

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////// this is what gameflow would look like.
    rules();

    deck deck1;
    int printDeck[52];
    int subDeck[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    vector<int> playerHand;
    vector<int> bankHand;
    int topOfDeck = 0;

    char wantCard;
    generateIndecies(printDeck, 52, 1);

    // Following two lines shuffles the printDeck. Creates a seed based on time and then shuffles the array.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(printDeck, printDeck + 52, std::default_random_engine(seed));

    // for (int i = 0; i < 52; i++) // Used for debugging: to check if printdeck is shuffled correctly
    // {
    //     std::cout << printDeck[i] << "\n";
    // }

    // dealer draws cards
    drawCard(printDeck, &bankHand, topOfDeck);
    topOfDeck++;
    drawCard(printDeck, &bankHand, topOfDeck);
    topOfDeck++;
    cout << "\nDealer's hand: " << endl;
    PrintCards(&deck1, &bankHand, true);

    drawCard(printDeck, &playerHand, topOfDeck);
    topOfDeck++;
    int subCard = 0;
    do
    {
        drawCard(printDeck, &playerHand, topOfDeck);
        topOfDeck++;
        cout << "\nYour hand: " << endl;
        PrintCards(&deck1, &playerHand, false);
        int handvalue = handValue(playerHand, 0, deck1) + subCard;
        cout << "Value of your hand: "<< handvalue << endl;

        if (handvalue < 21)
        {
            cout << "Do you want to draw another card? (Y/N)" << endl;
            cin >> wantCard;
        }
        else if (handvalue == 21)
        {
            cout << "You have 21, awating banks turn" << endl;
            break;
        }
        else
        {
            cout << "You go bust! Do you want a sub card? (Y/N)" << endl;
            cin >> wantCard;
            if (wantCard == 'y')
            {
                subCard = drawSubDeck(subDeck);
                cout << "Value of your sub card: " << subCard << endl;
                handvalue = handValue(playerHand, 0, deck1);
                handvalue += subCard;
                cout << "\nValue of your hand: " << handvalue << endl;
                break;
            }
            else
            {
                break;
            }
        }

    } while (wantCard == 'y');

    // begin bank logic
    int hit = 1;
    cout << "\nDealer reveals their hidden card: \n";
    int dealerValue = 0;
    while (hit == 1)
    {
        dealerValue = handValue(bankHand, 0, deck1);
        PrintCards(&deck1, &bankHand, false);
        cout << "\nValue of the dealer's hand: " << dealerValue;

        (dealerValue < 17) ? hit = 1 : hit = 0;
        if (hit == 1)
        {
            cout << "\nDealer draws a new card: \n";
            drawCard(printDeck, &bankHand, topOfDeck);
            topOfDeck++;
        }
        else
        {
            break;
        };
    };
    // evaluation of winner
    int playerValue = handValue(playerHand, 0, deck1) + subCard;
    dealerValue = handValue(bankHand, 0, deck1);
    (playerValue > dealerValue && playerValue <= 21 || dealerValue > 21) ? cout << "\nYou win!!" : cout << "\nHouse wins *womp womp*";

    return 0;
}
int drawSubDeck(int array[])
{
    srand(time(0));

    int randomIndex = rand() % -10;

    int randomValue = array[randomIndex];

    return randomValue;
}