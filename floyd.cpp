#include <iostream>
using namespace std;

void floyd(int D[10][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (D[i][j] > D[i][k] + D[k][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
}


int main()
{
    int n;
    int D[10][10];

    cout << "Enter the number of vertices (max 10): ";
    cin >> n;

    cout << "Enter the adjacency matrix (use 1000 for infinity):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> D[i][j];
        }
    }

    floyd(D, n);

    cout << "The shortest distances between every pair of vertices are:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (D[i][j] == 1000)
                cout << "1000 ";
            else
                cout << D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
