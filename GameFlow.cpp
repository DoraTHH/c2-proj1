#include <iostream>
#include <string.h>
#include <vector>
#include <C:\Chas\SUVx24\Kurs2\Blackjack++\deckmgmt.h>
#include <PrintCards.h>


int main () {
    

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////// this is what gameflow would look like.
   rules();

   deck deck1;

   char wantCard;
   int handvalue;
   drawCard(int deck1);
   do
   {
    drawCard();
    showHand();
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