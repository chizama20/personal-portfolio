
#include <iostream>
#include <string>

using namespace std;

class CaesarCipher {
private:
    int shiftValue;
public:
    CaesarCipher() : shiftValue(0) {}

    void setShiftValue(int value) {
        shiftValue = value;
    }

    string encode(const string& message) {
        string result = "";
        for (char c : message) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                char shifted = (c + shiftValue - base) % 26 + base;
                result += shifted;
            } else {
                result += c;
            }
        }
        return result;
    }

    string decode(const string& message) {
        string decodedMessage = "";
        for (char c : message) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                char shifted = (c - shiftValue - base + 26) % 26 + base;
                decodedMessage += shifted;
            } else {
                decodedMessage += c;
            }
        }
        return decodedMessage;
    }
};

class Rot13Cipher : public CaesarCipher {
public:
    Rot13Cipher() {
        setShiftValue(13); 
    }
};

int main() {
    string message;
    int shift;

    cout << "Do you want to encode a new message? (y/n or yes/no): ";
    string encodeOption;
    cin >> encodeOption;
    if (encodeOption == "y" || encodeOption == "yes") {
        cout << "Enter the message to be encoded: ";
        cin.ignore(); 
        getline(cin, message);

        cout << "Enter a shift value (1-13) to encode the message accordingly: ";
        cin >> shift;

        if (shift < 1 || shift > 13) {
            cerr << "Invalid shift value. Please enter a value between 1 and 13." << endl;
            return 1;
        }

        CaesarCipher cipher;
        cipher.setShiftValue(shift);
        string encodedMessage = cipher.encode(message);
        cout << "Encoded message using Caesar Cipher (shift value " << shift << "): " << encodedMessage << endl;
    }

    cout << "Do you want to decode the recent captured message? (y/n or yes/no) : ";
    string decodeOption;
    cin >> decodeOption;
    if (decodeOption == "y" || decodeOption == "yes") {
        cout << "Enter your guess for the shift value (1-13) to decode the message: ";
        cin >> shift;

        cout << "Enter the encoded message: ";
        cin.ignore();
        getline(cin, message);

        CaesarCipher cipher;
        cipher.setShiftValue(shift);
        string decodedMessage = cipher.decode(message);
        cout << "Decoding message using Caesar Cipher (shift value " << shift << ") :" << endl;
        cout << "Encoded Message: " << message << endl;
        cout << "Decoded message: " << decodedMessage << endl;

        string answer;
        cout << "Is the decoded message correct? (y/n or yes/no): ";
        cin >> answer;
        if (answer == "n" || answer == "no") {
            cout << "Do you want to try again with a different shift value? (y/n or yes/no) : ";
            cin >> answer;
            if (answer == "y" || answer == "yes") {
                cout << "Correct answer!";
            }else{
                cout << "Incorrect.";
            }
        }
    }

    return 0;
}
