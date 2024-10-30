#include <iostream>
#include <string>
#include <vector>

void rules() {
    std::cout << "Blackjack Rules:\n";
    std::cout << "1. Objective: Get a hand value closer to 21 than the dealer without going over 21.\n";
    std::cout << "2. Card Values:\n";
    std::cout << "   - Number cards (2-10) = face value\n";
    std::cout << "   - Face cards (J, Q, K) = 10 points\n";
    std::cout << "   - Ace = 1 or 11 points\n";
    std::cout << "3. Gameplay:\n";
    std::cout << "   - Players and the dealer get two cards each.\n";
    std::cout << "   - Players can 'hit' (take another card) or 'stand' (keep their current hand).\n";
    std::cout << "   - Players can 'double down' (double the bet, take one more card) or 'split' (if they have two cards of the same value).\n";
    std::cout << "4. Winning:\n";
    std::cout << "   - Bust (over 21) = lose\n";
    std::cout << "   - Closest to 21 without busting wins\n";
    std::cout << "   - Tie (same value as dealer) = push (bet returned)\n";
    std::cout << "5. Dealer Rules:\n";
    std::cout << "   - Dealer hits until reaching at least 17.\n";
    std::cout << "   - Dealer stands on 17 or higher.\n";
}
