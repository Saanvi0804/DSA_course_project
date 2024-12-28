#include <iostream>
using namespace std;

struct Data {
    int a;
    float b;
    char c;
};

void DisplayArray(Data arr[], int size) {
    cout << "Array of Structures:\n";
    for (int i = 0; i < size; i++) 
        cout << "Element " << i + 1 << " - a: " << arr[i].a << ", b: " << arr[i].b << ", c: " << arr[i].c << endl;
}


int main() 
{
    Data arr[100]; 
    int n; 

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements (a b c):\n";
    for (int i = 0; i < n; i++) 
        cin >> arr[i].a >> arr[i].b >> arr[i].c;

    cout << "Entered array:\n";
    DisplayArray(arr, n);

    return 0;
}
