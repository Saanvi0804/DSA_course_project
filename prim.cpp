#include <iostream>
#include <algorithm>
using namespace std;

class Prim {
public:
    int path[4];
    int dist[4];
    int mst[4];

    void initialize(int cost[4][4], int source);
    int minimum();
    void updation(int cost[4][4]);
    void primMST(int cost[4][4], int source);
    void printMST(int cost[4][4]);
    void printTotalCost(int cost[4][4]);
};

void Prim::initialize(int cost[4][4], int source)
{
    int i;
    for (i=0;i<4;i++)
    {
        path[i]=source;
        dist[i]=(cost[source][i] == 0) ? 10000000 : cost[source][i];
        mst[i]=0;
    }
    dist[source]=0;
    mst[source]=1;
}

int Prim::minimum()
{
    int i;
    int mini=10000000;
    int minIndex=-1;
    for (i=0;i<4;i++)
    {
        if (!mst[i] && dist[i] < mini)
        {
            mini=dist[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void Prim::updation(int cost[4][4])
{
    int i;
    int u=minimum();
    if (u==-1)
        return;
    mst[u]=1;
    for (i=0; i<4; i++)
    {
        if (mst[i]==0 && cost[u][i])
        {
            dist[i] = min(dist[i], cost[u][i]);
            if (dist[i]==cost[u][i])
                path[i]=u;
        }
    }
}

void Prim::primMST(int cost[4][4], int source) {
    initialize(cost, source);
    for (int i = 0; i < 3; i++)
        updation(cost);
}

void Prim::printMST(int cost[4][4])
{
    int i;
    cout << "Edge \tWeight" << endl;
    for (i= 0; i<4; i++)
    {
        if (path[i]!=-1 && path[i]!=i)
            cout << path[i] << " - " << i << " \t" << cost[path[i]][i] << endl;
    }
}

void Prim::printTotalCost(int cost[4][4]) {
    int totalCost = 0;
    for (int i=0; i<4; i++) {
        if (path[i]!=-1 && path[i]!=i) {
            totalCost += cost[path[i]][i];
        }
    }
    cout << "Total cost of the Minimum Spanning Tree: " << totalCost << endl;
}

int main()
{
    int source;
    int cost[4][4];
    cout << "Enter the cost matrix\n";
    for (int i=0; i<4;i++)
    {
        for (int j=0; j<4; j++)
            cin >> cost[i][j];
    }
    cout << "Enter the source vertex: ";
    cin >> source;
    Prim prim;
    prim.primMST(cost, source);
    prim.printMST(cost);
    prim.printTotalCost(cost);
    return 0;
}
