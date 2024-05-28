#include <iostream>
#include <string>

using namespace std;

class Creature {
protected:
    string name;
    int quantity;
    string creature_type;

public:
    Creature() : quantity(0), creature_type("unknown") {} // Default constructor

    Creature(const string& name, int quantity) : name(name), quantity(quantity), creature_type("unknown") {} // Parameterized constructor

    void setName(const string& name) {
        this->name = name;
    }

    string getName() const {
        return name;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    int getQuantity() const {
        return quantity;
    }

    virtual void printStatement() const {
        cout << "There's " << quantity << " creatures named " << name << "." << endl;
    }
};

class Phoenix : public Creature {
private:
    string color;

public:
    Phoenix() : color("") {} 

    Phoenix(const string& name, int quantity, const string& color) : Creature(name, quantity), color(color) {}
    void setColor(const string& color) {
        this->color = color;
    }

    string getColor() const {
        return color;
    }

    virtual void printStatement() const override {
        cout << "There's " << quantity << " creatures named " << name << " with color " << color << "." << endl;
    }
};

class Basilisk : public Creature {
public:
    Basilisk() : Creature("Clover", 1) {} // Default constructor

    Basilisk(const string& name) : Creature(name, 1) {} // Parameterized constructor

    virtual void printStatement() const override {
        cout << "There's " << quantity << " creatures named " << name << "." << endl;
    }
};

int main() {
    string nameArr[3];
    string name;

    for (int i = 0; i < 3; ++i) {
        cin >> name;
        nameArr[i] = name;
        if (i == 2) {
            nameArr[i] = "Clover";
        }
    }

    Creature c(nameArr[0], 2); 
    c.printStatement(); 

    Phoenix p; 
    p.setName(nameArr[1]);
    p.setQuantity(3);
    p.setColor("golden");
    p.printStatement(); 

    Basilisk b; 
    b.setName(nameArr[2]);
    b.printStatement(); 

    return 0;
}
