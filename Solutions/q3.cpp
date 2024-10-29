
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    private:
        string name;
        int score;

    public:
        Player() : name(""), score(0) {}
        Player(string newName, int newScore) : name(newName), score(newScore) {}

        void setName(string newName) { name = newName; }
        void setScore(int newScore) { score = newScore; }

        string getName() const { return name; }
        int getScore() const { return score; }
};


// Function declarations
void addPlayer(vector<Player>& players);
void printPlayers(const vector<Player>& players);
void findPlayer(const vector<Player>& players);
void removePlayer(vector<Player>& players);

int main() {
    vector<Player> players;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new player\n";
        cout << "2. Print all players and scores\n";
        cout << "3. Find a player's score\n";
        cout << "4. Remove a player\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addPlayer(players);
                break;
            case 2:
                printPlayers(players);
                break;
            case 3:
                findPlayer(players);
                break;
            case 4:
                removePlayer(players);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new player
void addPlayer(vector<Player>& players) {
    if (players.size() >= 10) {
        cout << "Player list is full (maximum of 10 players).\n";
        return;
    }

    string name;
    int score;
    cout << "Enter player name: ";
    cin >> name;
    cout << "Enter player score: ";
    cin >> score;

    players.push_back(Player(name, score));
    cout << "Player added successfully.\n";
}

// Function to print all players
void printPlayers(const vector<Player>& players) {
    if (players.empty()) {
        cout << "No players to display.\n";
        return;
    }

    cout << "Player List:\n";
    for (const auto& player : players) {
        cout << "Name: " << player.getName() << ", Score: " << player.getScore() << endl;
    }
}

// Function to find a player's score by name
void findPlayer(const vector<Player>& players) {
    string name;
    cout << "Enter player name to find score: ";
    cin >> name;

    bool found = false;
    for (const auto& player : players) {
        if (player.getName() == name) {
            cout << "Player " << name << " has a score of " << player.getScore() << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Player not found.\n";
    }
}

// Function to remove a player by name
void removePlayer(vector<Player>& players) {
    string name;
    cout << "Enter player name to remove: ";
    cin >> name;

    for (auto it = players.begin(); it != players.end(); ++it) {
        if (it->getName() == name) {
            players.erase(it);
            cout << "Player " << name << " removed successfully.\n";
            return;
        }
    }

    cout << "Player not found.\n";
}
