#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

int main() {
    srand(time(0)); 

    int randomNumber = rand() % 10 + 1; // Generate random number between 1 and 10
    int guess;
    int tries = 0;
    bool guessedCorrectly = false;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I've picked a number between 1 and 10. Try to guess it!" << endl;

    while (!guessedCorrectly) {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess == randomNumber) {
            guessedCorrectly = true;
            cout << "Congratulations! You guessed the correct number in " << tries << " tries." << endl;
        } else {
            if (guess < 1 || guess > 10) {
                cout << "Invalid guess. Please enter a number between 1 and 10." << endl;
            } else {
                if (guess < randomNumber) {
                    cout << "Too low! Try a higher number." << endl;
                } else {
                    cout << "Too high! Try a lower number." << endl;
                }
                // Additional feedback
                int difference = abs(guess - randomNumber);
                if (difference == 1) {
                    cout << "You're getting really close!" << endl;
                } else if (difference <= 2) {
                    cout << "You're close! Keep trying." << endl;
                } else {
                    cout << "You can do it! Keep guessing." << endl;
                }
            }
        }
    }

    return 0;
}
