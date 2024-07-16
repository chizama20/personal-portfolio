/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

void drawBoard(const vector<char>& board) {
    system("clear");
    cout << "  " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << " -----------" << endl;
    cout << "  " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << " -----------" << endl;
    cout << "  " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool isGameOver(const vector<char>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6])
            return true; 
        if (board[i * 3] != ' ' && board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2])
            return true;
    }
    if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8])
        return true; 
    if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6])
        return true; 

    for (char c : board) {
        if (c == ' ')
            return false; 
    }
    return true;
}

int getUserMove(const vector<char>& board) {
    int move;
    cout << "Enter your move (1-9): ";
    cin >> move;
    while (move < 1 || move > 9 || board[move - 1] != ' ') {
        cout << "Invalid move. Enter your move (1-9): ";
        cin >> move;
    }
    return move;
}

int main() {
    vector<char> board(9, ' '); 
    int currentPlayer = 0; 
    int move;

    while (!isGameOver(board)) {
        drawBoard(board);
        move = getUserMove(board);
        board[move - 1] = currentPlayer == 0 ? 'X' : 'O';
        currentPlayer = 1 - currentPlayer;
    }

    drawBoard(board);
    if (isGameOver(board))
        cout << "Game Over!" << endl;
    else
        cout << "It's a draw!" << endl;

    return 0;
}
