#include <iostream>
#include <string>
using namespace std;

void rules()
{
    cout << "Blackjack Rules:\n";
    cout << "1. Objective: Get a hand value closer to 21 than the dealer without going over 21.\n";
    cout << "2. Card Values:\n";
    cout << "   - Number cards (2-10) = face value\n";
    cout << "   - Face cards (J, Q, K) = 10 points\n";
    cout << "   - Ace = 1 or 11 points\n";
    cout << "3. Gameplay:\n";
    cout << "   - Players and the dealer get two cards each.\n";
    cout << "   - Players can 'hit' (take another card) or 'stand' (keep their current hand).\n";
    cout << "   - Players can 'double down' (double the bet, take one more card) or 'split' (if they have two cards of the same value).\n";
    cout << "4. Winning:\n";
    cout << "   - Bust (over 21) = lose\n";
    cout << "   - Closest to 21 without busting wins\n";
    cout << "   - Tie (same value as dealer) = push (bet returned)\n";
    cout << "5. Dealer Rules:\n";
    cout << "   - Dealer hits until reaching at least 17.\n";
    cout << "   - Dealer stands on 17 or higher.\n";

    
}
 int main()
{
    rules();
    return 0;
}