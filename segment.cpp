#include <iostream>
#include <climits> 
using namespace std;
#define MAX 100

class segtree 
{
public:
    int size;
    int tree[MAX * 4]; 
    void build(int index, int low, int high, int arr[]);
    int query(int index, int low, int high, int l, int r);
    segtree(int n, int arr[]);
};

segtree::segtree(int n, int arr[]) 
{
    size = n;
    build(0, 0, n - 1, arr);
}

void segtree::build(int index, int low, int high, int arr[]) 
{
    if (low == high) 
        tree[index] = arr[low];
    else 
    {
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
    }
}


int segtree::query(int index, int low, int high, int l, int r) 
{
    if (low > r || high < l) 
        return INT_MAX; 
    
    if (low >= l && high <= r) 
        return tree[index];
    
    int mid = (low + high) / 2;
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return min(left, right);
}

int main()
{
    int n, q;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[MAX];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
  
    segtree segmenttree(n, arr);

    cout << "Enter the number of queries: ";
    cin >> q;

    for (int i = 0; i < q; i++) 
    {
        int l, r;
        cout << "Enter the range (l r): ";
        cin >> l >> r;
        cout << "Minimum in range [" << l << ", " << r << "] is "
             << segmenttree.query(0, 0, n - 1, l - 1, r - 1) << endl;
    }

    return 0;
}
