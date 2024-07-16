/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string words[] = {
    "japan",
    "turkey",
    "nepal",
    "malaysia",
    "philippines",
    "australia",
    "america",
    "ethiopia",
    "oman",
    "indonesia"
};

int main() {
    srand(time(NULL));
    int n = rand() % 10;
    string word = words[n];

    string hidden(word.length(), '*'); // Initialize hidden word with asterisks
    int strikes = 0;
    bool found;
    char guess;

    cout << "Welcome to Hangman!" << endl;
    cout << "Guess the word: " << hidden << endl;

    while (strikes < 5 && hidden != word) {
        found = false;
        cout << "Enter a letter guess: ";
        cin >> guess;

        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                hidden[i] = guess;
                found = true;
            }
        }

        if (!found) {
            strikes++;
            cout << "Incorrect guess! You have " << 5 - strikes << " tries left." << endl;
        } else {
            cout << "Correct guess! Word so far: " << hidden << endl;
        }
    }

    if (hidden == word) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "Sorry, you didn't guess the word. The word was: " << word << endl;
    }

    return 0;
}
