#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum selector{rock, paper, scissor};
int winnerDeterminate();

int main(){
    cout<< "Do you think you can beat me in rock, paper, scissor? 1v1 me. ";
    cout<<"1. Rock  2. Paper  3. Scissor: ";
    
    srand(static_cast<unsigned int>(std::time(0)));
    winnerDeterminate();
    return 0;
}

int winnerDeterminate(int player, int randomNumber, int rock, int paper, int scissor, int selector){
    
    randomNumber = rand() % 3 + 1;

    cin>> player;
    rock = 1;
    paper = 2;
    scissor = 3;

    if(player == randomNumber){
        cout<<"It's a tie";
    }
    else if((player == 1 && randomNumber == 2) || (player == 2 && randomNumber == 3) || (player == 3 && randomNumber == 1)){
        cout<<"you lost";
    }
    else{
        cout<<" you won";
    }
}