#include <iostream>
#include <string>
#include <vector>

class Player {
public:
    Player(const std::string& name) 
        : name(name), balance(0), points(0) {} 

    std::string getName() const { return name; }
    int getPoints() const { return points; }
    int getBalance() const { return balance; }

    void addBalance(int amount) {
        balance += amount; // + balance
        // Add points if balance reaches 21
        if (balance == 21) {
            addPoints(1); // Add points when balance reaches 21
        }
    }

    void resetPoints() {
        points = 0;
    }

    void displayStatus() const {
        std::cout << "Player: " << name  
                  << ", Balance: " << balance
                  << ", Points: " << points << std::endl;
    }

private:
    std::string name;
    int balance; // New balance variable
    int points;

    void addPoints(int amount) {
        points += amount; // Increment points
    }
};

class PlayerDatabase {
public:
    void addPlayer(const std::string& name) {
        players.emplace_back(name); // Add a new Player to the vector
    }

    Player* findPlayer(const std::string& name) {
        for (auto& player : players) {
            if (player.getName() == name) {
                return &player; // Return a pointer to the found player
            }
        }
        return nullptr; // Return nullptr if not found
    }

    void displayPlayers() const {
        for (const auto& player : players) {
            player.displayStatus(); // Display each player's status
        }
    }

private:
    std::vector<Player> players; // Vector to store players
};

int main() {
    PlayerDatabase db;

    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    db.addPlayer(name); // Add the player to the database

    // Simulate balance changes (this part of the code needs fixing)
    Player* player = db.findPlayer(name);
    if (player) {
        player->addBalance(10); // Add some balance
        player->addBalance(11); // Add balance to reach 21
        std::cout << "After adding balance:" << std::endl;
        db.displayPlayers(); // Display updated status
    } else {
        std::cout << "Player not found!" << std::endl;
    }

    return 0;
}
