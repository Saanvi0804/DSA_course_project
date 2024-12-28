#include <iostream>
using namespace std;
const int MAX = 20;

int n, arr[MAX], BIT[MAX];

class FenwickTree 
{
public:
    FenwickTree(int n);
    void build();
    void update(int x, int delta);
    int query(int x);
    int sum();
};

FenwickTree::FenwickTree(int n) 
{
    for (int i = 0; i <= n; i++) 
        BIT[i] = 0;
}

void FenwickTree::build() 
{
    for (int i = 1; i <= n; i++) 
    {
        cin >> arr[i];
        update(i, arr[i]);
    }
}

void FenwickTree::update(int x, int delta) 
{
    for (; x <= n; x += x & -x)
        BIT[x] += delta;
}

int FenwickTree::query(int x) 
{
    int sum = 0;
    while (x > 0) 
    {
        sum += BIT[x];
        x -= x & -x;
    }
    return sum;
}

int FenwickTree::sum() 
{
    return query(n);
}

int main() {
    cout << "Enter the size of the array: ";
    cin >> n;
    FenwickTree fenwickTree(n);
    cout << "Enter the array elements: " << endl;
    fenwickTree.build();
    cout << "The total sum is: " << fenwickTree.sum() << endl;
    return 0;
}
