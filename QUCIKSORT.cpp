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

    do {
        do
            i++;
        while (A[i] < p && i <= r);

        do
            j--;
        while (A[j] > p && j >= l);

        if (i >= j) break;
        swap(A[i], A[j]);
    } while (true);

    swap(A[l], A[j]);
    return j;
}

void QuickSort(int A[], int l, int r) 
{
    if (l < r) {
        int s = Partition(A, l, r);
        QuickSort(A, l, s - 1);
        QuickSort(A, s + 1, r);
    }
}

void PrintArray(int A[], int size)
{
    for (int i = 0; i < size; i++) {
        cout<<A[i] <<" ";
    }
    cout<<endl;
}

int main()
{
    int A[100];
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }

    cout<<"Unsorted array: ";
    PrintArray(A, n);

    QuickSort(A, 0, n - 1);

    cout<<"Sorted array: ";
    PrintArray(A, n);

    return 0;
}
