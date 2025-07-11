#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int guess, attempts = 1;

    srand(time(NULL));
    int random_number = rand() % 100 + 1; // Range: 1 to 100

    cout << "========================================\n";
    cout << "   WELCOME TO THE NUMBER GUESSING GAME\n";
    cout << "========================================\n\n";

    cout << "I have picked a number between 1 and 100.\n";
    cout << "Can you guess what it is?\n";
    cout << "Let's find out!\n\n";

    cout << "Enter your guess: ";
    cin >> guess;

    while (guess != random_number) {
        attempts++;

        if (guess < random_number) {
            cout << "Oops! That's too low. Try a bigger number.\n";
        } else {
            cout << "Whoa! That's too high. Try a smaller number.\n";
        }

        cout << "\nTake another shot: ";
        cin >> guess;
    }

    cout << "\n Great job! You guessed it right!\n";
    cout << "The number was: " << random_number << "\n";
    cout << "It took you " << attempts << " attempt(s) to win.\n";
    cout << "Thanks for playing \n";

    return 0;
}
