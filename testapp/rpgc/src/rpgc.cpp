#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(0)); 
    int crackerSanity = 100;
    int playerExperience = 0;
    int enemySanity = 50;
    int enemyAttack = 10;
    int playerAttack = 15;
    int timeElapsed = 0;
    auto startTime = high_resolution_clock::now(); 
    cout << "Welcome to the RPG Console Game!" << endl;
    cout << "You are a brave cracker. Your journey begins now." << endl;
    while (crackerSanity > 0 && enemySanity > 0) {
        cout << "\n--- Turn ---" << endl;
        cout << "Your Sanity: " << crackerSanity << endl;
        cout << "Enemy Sanity: " << enemySanity << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defend" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            enemySanity -= playerAttack;
            cout << "You hurt the enemy for " << playerAttack << " damage." << endl;
            if (enemySanity > 0) {
                crackerSanity -= enemyAttack;
                cout << "The enemy hurt you for " << enemyAttack << " damage." << endl;
            } else {
                cout << "You defeated the enemy!" << endl;
                playerExperience += 100;
                cout << "You gained 100 experience points." << endl;
            }
        } else if (choice == 2) {
            cout << "You defended yourself." << endl;
            crackerSanity -= enemyAttack / 2;
            cout << "The enemy attacked you for " << enemyAttack / 2 << " damage." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
        this_thread::sleep_for(milliseconds(1000)); 
        auto endTime = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(endTime - startTime);
        timeElapsed = duration.count();
    }
    cout << "\nGame Over!" << endl;
    cout << "Total Time Elapsed: " << timeElapsed << " seconds" << endl;
    cout << "Final Health: " << crackerSanity << endl;
    cout << "Final Experience: " << playerExperience << endl;
    return 0;
}
