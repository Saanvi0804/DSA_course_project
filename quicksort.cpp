#include <iostream>
using namespace std;

void swap(int& a, int& b) 
{
    int t = a;
    a = b;
    b = t;
}

int Partition(int A[], int l, int r) 
{
    int p = A[l];
    int i = l;
    int j = r + 1;

    do 
    {
        do 
            i++;
        while (A[i] < p && i <= r);

        do
            j--;
        while (A[j] > p && j >= l);

        if (i >= j) break;
        swap(A[i], A[j]);
    } 
        while (true);

    swap(A[l], A[j]);
    return j;
}

void QuickSort(int A[], int l, int r) 
{
    if (l < r) 
    {
        int s = Partition(A, l, r);
        QuickSort(A, l, s - 1);
        QuickSort(A, s + 1, r);
    }
}

void PrintArray(int A[], int size) 
{
    for (int i = 0; i < size; i++) 
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int choice;
    int A[100];
    int n = 0; 

    while (1) 
    {
        cout << "\nMenu:\n";
        cout << "1. Input array\n";
        cout << "2. Display array\n";
        cout << "3. Sort array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter the number of elements: ";
            cin >> n;
            cout << "Enter the elements: ";
            for (int i = 0; i < n; i++) 
                cin >> A[i];
            
            break;

        case 2:
            if (n == 0)
                cout << "Array is empty. Please input the array first.\n";
            else {
                cout << "Current array: ";
                PrintArray(A, n);
            }
            break;

        case 3:
            if (n == 0) 
                cout << "Array is empty. Please input the array first.\n";
            else 
            {
                QuickSort(A, 0, n - 1);
                cout << "Array sorted.\n";
            }
            break;

        case 4:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
