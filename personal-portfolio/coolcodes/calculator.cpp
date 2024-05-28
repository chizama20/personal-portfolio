#include <iostream>

using namespace std;

void showChoice() {
    cout << "Menu\n"
         << "1. Add\n"
         << "2. Subtract\n"
         << "3. Multiply\n"
         << "4. Divide\n"
         << "5. Exit\n";
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero\n";
        return 0;
    }
}

int main() {
    float a, b;
    int choice;

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    do {
        showChoice();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Result: " << add(a, b) << endl;
                break;
            case 2:
                cout << "Result: " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Result: " << multiply(a, b) << endl;
                break;
            case 4:
                cout << "Result: " << divide(a, b) << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
