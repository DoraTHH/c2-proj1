#include <iostream>
#include <string.h>
#include <vector>
//#include <C:\Chas\SUVx24\Kurs2\Blackjack++\deckmgmt.h>
#include "PrintCards.h"
#include "deckmgmt.h"
using namespace std;


main ()
{


   //////////////////////////////////////////////////////////////////////////////////////////////////////////////// this is what gameflow would look like.
   rules();

   deck deck1;
   int printDeck[52];
   vector<int> playerHand;
   vector<int> bankHand;
   int topOfDeck = 0;

   char wantCard;
   generateIndecies (printDeck, 52, 1);
   drawCard(printDeck,&playerHand, topOfDeck);
   topOfDeck++;
   do
   {
    drawCard(printDeck,&playerHand, topOfDeck);
   topOfDeck++;
    showHand(playerHand, 0, deck1);
   int handvalue = handValue (playerHand, 0, deck1);
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
    }
    
   } while (wantCard == 'y');

   
   
   //begin bank logic
   //evaluation of winner

}
