
#include <ctime>
#include <random>
#include <chrono>
#include <algorithm>
#include "DisplayCards.h"
#include "deckmgmt.h"
#include <cstdlib>     /*For rand() and srand()*/ 
#include <ctime>     /*For time*/

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
        int subCard=drawSubDeck(subDeck);
    cout << subCard << endl;
    drawCard(printDeck, &playerHand, topOfDeck);
        topOfDeck++;
        PrintCards(&deck1, &playerHand, false);
        int handvalue = handValue(playerHand, 0, deck1) + subCard;
   cout << handvalue << endl;


        if (handvalue < 21)
        {
            cout << "Do you want to draw another card? (Y/N)" << endl;
            cin >> wantCard;
        }
        else if (handvalue == 21)
        {
            cout << "You have 21, awating banks turn" << endl;
        }
        else
        {
            cout << "The Bank wins!" << endl;
            wantCard = 'n';
        }

    } while (wantCard == 'y');

    // begin bank logic
    // evaluation of winner

    return 0;
}
int drawSubDeck(int array[])
{
  srand(time(0));

  int randomIndex = rand() % -10;

  int randomValue = array[randomIndex];

  return randomValue;  
}