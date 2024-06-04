#include <iostream>
#include <string>

using namespace std;
string item;
int quantity;
float price;

void getitemdetails(){
    cout << "Enter the name of item: ";
    cin >> item;
    cout << "Enter the quantity of item: ";
    cin >> quantity;
    cout << "Enter the price of item: ";
    cin >> price;

}

void displayItems(){
    float cost = quantity * price;
    cout << "Item: " << item << ", Quantity: " << quantity << ", Price: $" << price << ", Cost: $" << cost << endl;
}


int main(){
    int numItems, i = 0;
    float totalCost = 0.0;

    cout << "Enter number of items: ";
    cin >> numItems;

    while(i < numItems){
        getitemdetails();
        float cost = quantity * price;
        totalCost += cost;
        i++;
    }

    displayItems();

    float discountPercent;

    cout << "Enter discount percentage: ";
    cin >> discountPercent;

    float discount = totalCost * (discountPercent / 100);
    float finalCost = totalCost - discount;

    cout << "Total cost before discount: " << totalCost << endl;
    cout << "Discount applied: " << discount << endl;
    cout << "Final cost after discount: " << finalCost << endl;

    return 0;
}