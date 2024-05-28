#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> 

using namespace std;

string AIResponse(int question) {
    if (question == 1)
        return "AI response: May 25";
    else if (question == 2)
        return "AI response: Lemonade";
    else if (question == 3)
        return "AI response: 2";
    else if (question == 4)
        return "AI response: Electrical Engineering";
    else if (question == 5)
        return "AI response: Of course he is";
    else
        return "AI response: I don't have a response for that question";
}

int main() {
    const int NUM_QUESTIONS = 5;
    string arrQuestions[NUM_QUESTIONS] = {
        "When is chi's birthday",
        "What is his favorite drink",
        "How many siblings does chi have",
        "What is his major",
        "Is chi the goat?"
    };
    bool arrAnswers[NUM_QUESTIONS] = {false, true, false, false, true};

    cout << "Welcome to the maze!!!\nTo pass through you need to answer these true and false questions right\n";

    int points = 0;
    int strikes = 0;
    bool answered[NUM_QUESTIONS] = {false};

    for(int i = 0; i < NUM_QUESTIONS; ++i) {
        cout << "\nChoose one question number (1-5): ";
        int questionNum;
        cin >> questionNum;

        if (questionNum < 1 || questionNum > NUM_QUESTIONS) {
            cout << "Number is not within 1-5\n";
            i--; 
            continue; 
        }

        if (answered[questionNum - 1]) {
            cout << "You have already answered this question. Choose a different one.\n";
            i--; 
            continue;
        }

        answered[questionNum - 1] = true;

        cout << "Question: " << arrQuestions[questionNum - 1] << endl;

        cout << AIResponse(questionNum) << endl;

        cout << "Your answer (True/False): ";
        string userAnswerStr;
        cin >> userAnswerStr;

        transform(userAnswerStr.begin(), userAnswerStr.end(), userAnswerStr.begin(), ::tolower);

        bool userAnswer = (userAnswerStr == "true");

        if (userAnswer == arrAnswers[questionNum - 1]) {
            cout << "\nRight Choice!\n";
            points++;
        } else {
            cout << "\nWrong choice\n";
            strikes++;
        }
    }

    if (strikes == 3) {
        cout << "You got 3 strikes, Game over\n";
    } else if (points == NUM_QUESTIONS) {
        cout << "Winner Winner Chicken Dinner\n";
    }

    cout << "\nActual Answers:\n";
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        cout << arrQuestions[i] << ": " << (arrAnswers[i] ? "True" : "False") << endl;
    }

    cout << "Total Points: " << points << endl;
    return 0;
}
