#include <iostream>
using namespace std;

struct pairs {
    int u;
    int v;
    int w;
};

class kruksal {
public:
    int arr[100];
    int n;

    kruksal() {
        cout << "Enter the number of vertices (up to 100): ";
        cin >> n;
        for (int i = 0; i < n; i++)
            arr[i] = i;
    }

    void Union(int u, int v);
    int Find(int u);
    void quickSort(pairs arr[], int low, int high);
    int partition(pairs arr[], int low, int high);
    void swap(pairs& a, pairs& b);
};

void kruksal::Union(int u, int v) {
    int temp = arr[u];
    for (int i = 0; i < n; i++) {
        if (arr[i] == temp) {
            arr[i] = arr[v];
        }
    }
}

int kruksal::Find(int u) {
    return arr[u];
}

void kruksal::swap(pairs& a, pairs& b) {
    pairs t = a;
    a = b;
    b = t;
}

int kruksal::partition(pairs arr[], int low, int high) {
    pairs pivot = arr[low];
    int i = low;
    int j = high + 1;

    do {
        do {
            i++;
        } while (i <= high && ((arr[i].w < pivot.w) || (arr[i].w == pivot.w && arr[i].u < pivot.u) || (arr[i].w == pivot.w && arr[i].u == pivot.u && arr[i].v < pivot.v)));

        do {
            j--;
        } while (j >= low && ((arr[j].w > pivot.w) || (arr[j].w == pivot.w && arr[j].u > pivot.u) || (arr[j].w == pivot.w && arr[j].u == pivot.u && arr[j].v > pivot.v)));

        if (i >= j)
            break;
        swap(arr[i], arr[j]);
    } while (true);

    swap(arr[low], arr[j]);
    return j;
}

void kruksal::quickSort(pairs arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    kruksal kruskal;  
    int num_edges;
    cout << "Enter the number of edges: ";
    cin >> num_edges;

    pairs A[100]; 

    cout << "Enter the edges (u v w) one by one:\n";
    for (int i = 0; i < num_edges; i++) {
        cout << "Edge " << i + 1 << ": ";
        cin >> A[i].u >> A[i].v >> A[i].w;
    }

    kruskal.quickSort(A, 0, num_edges - 1);

    for (int k = 0; k < num_edges; k++) {
        int i = kruskal.Find(A[k].u);
        int j = kruskal.Find(A[k].v);
        if (i != j) {
            kruskal.Union(i, j);
            cout << "Edge (" << A[k].u << ", " << A[k].v << ", " << A[k].w << ") added to the MST" << endl;
        }
    }

    return 0;
}
