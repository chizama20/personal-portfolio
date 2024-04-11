#include <iostream>
#include <cmath>

using namespace std;

class Arena{
    public:
    int radius;
    void display(){
        int size = pow(radius, 2);
        cout << size << endl;
    }

};

class ArenaArea : public Arena{
    public:
    void scan_input(){
        cin >> radius;
    }
    void display(){
        float area = pow(radius, 2) * 3.14;
        cout << area << endl;
    }
};

int main(){

    ArenaArea stadium;
    stadium.scan_input();
    stadium.Arena::display();
    cout << endl;
    stadium.display();

    return 0;
}
/*dont change the main*/