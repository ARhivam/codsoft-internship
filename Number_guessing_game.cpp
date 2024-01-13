#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    // Initialize variables
    int guessedNumber = 0;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "Try to guess the secret number between 1 and 100." << endl;

    while (guessedNumber != secretNumber) {
        // Get user input for the guess
        cout << "Enter your guess: ";
        cin >> guessedNumber;

        // Increment the attempts counter
        attempts++;

        // Provide feedback on the guess
        if (guessedNumber < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guessedNumber > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts." << endl;
        }
    }

    return 0;
}
