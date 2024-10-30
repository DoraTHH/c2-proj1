#include <iostream>
#include <vector>

int drawCard() { return rand() % 11 + 1; }

void displayHand(const std::vector<int> &hand)
{
    std::cout << "Din hand: ";
    for (int card : hand)
        std::cout << card << " ";
    std::cout << std::endl;
}

int sumHand(const std::vector<int> &hand)
{
    int total = 0;
    for (int card : hand)
        total += card;
    return total;
}

void handlePlayerChoice(std::vector<int> &hand)
{
    int choice;
    while (true)
    {
        std::cout << "1. Dra ett kort\n2. Stanna\nAnge ditt val: ";
        std::cin >> choice;
        if (choice == 1)
        {
            hand.push_back(drawCard());
            displayHand(hand);
            if (sumHand(hand) > 21)
            {
                std::cout << "Över 21, spelet slutar.\n";
                break;
            }
        }
        else if (choice == 2)
        {
            std::cout << "Du valde att stanna.\n";
            break;
        }
    }
}

int main()
{
    srand(time(0));
    std::vector<int> playerHand;
    handlePlayerChoice(playerHand);
    return 0;
}
