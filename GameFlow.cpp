#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>


   //////////////////////////////////////////////////////////////////////////////////////////////////////////////// this is what gameflow would look like.
   char wantCard;
   int handvalue;
   drawCard();
   do
   {
    drawcard();
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

