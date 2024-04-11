#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber() {
    srand(time(0));
    return rand() % 10 + 1;
}

void playGame(double &balance) {
    int guess, bet;
    int randomNumber = generateRandomNumber();

    cout << "Enter your guess (between 1 and 10): ";
    cin >> guess;

    while (guess < 1 || guess > 10) {
        cout << "Invalid guess. Please enter a number between 1 and 10: ";
        cin >> guess;
    }

    cout << "Enter your bet: $";
    cin >> bet;

    while (bet > balance || bet <= 0) {
        cout << "Invalid bet. Please enter a valid amount: $";
        cin >> bet;
    }

    if (guess == randomNumber) {
        cout << "Congratulations! You guessed the correct number. You win $" << bet * 10 << endl;
        balance += bet * 10;
    } else {
        cout << "Sorry, you guessed wrong. You lose $" << bet << endl;
        balance -= bet;
    }

    cout << "Your current balance is: $" << balance << endl;
}

int main() {
    double balance;
    char playAgain;

    cout << "Welcome to the Casino Number Guessing Game!" << endl;
    cout << "Please deposit some money to start playing: $";
    cin >> balance;

    while (balance > 0) {
        playGame(balance);
        if (balance <= 0) {
            cout << "You've run out of balance to bet. Thanks for playing!" << endl;
            break;
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing!" << endl;
            break;
        }
    }

    return 0;
}
