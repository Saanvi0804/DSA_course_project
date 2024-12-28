#include <iostream>
#include <string>
using namespace std;

struct InventoryItem 
{
    string name;
    int quantity;
    double price;
};

int main() 
{
    const int MAX_ITEMS = 5;
    InventoryItem items[MAX_ITEMS];

    for (int i = 0; i < MAX_ITEMS; i++) 
    {
        cout << "Enter details for item " << i + 1 << endl;
        cout << "Name: ";
        cin >> items[i].name;
        cout << "Quantity: ";
        cin >> items[i].quantity;
        cout << "Price: ";
        cin >> items[i].price;
        cout << endl;
    }

    cout << "Inventory Details:" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) 
    {
        cout << "Item " << i + 1 << ": " << endl;
        cout << "Name: " << items[i].name << endl;
        cout << "Quantity: " << items[i].quantity << endl;
        cout << "Price: $" << items[i].price << endl;
        cout << endl;
    }

    return 0;
}
