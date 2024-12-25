#include<iostream>
#include<algorithm>
using namespace std;

class dijkstra
{
public:
    int path[4];
    int dist[4];
    int visited[4];
    void initialise(int cost[4][4], int source);
    int minimum();
    void updation(int cost[4][4]);
    void shortest_path(int cost[4][4],int source);
    void print(int source);
};

void dijkstra::initialise(int cost[4][4],int source)
{
    int i;
    for(i=0;i<4;i++)
    {
        path[i]=source;
        dist[i] = (cost[source][i] == 0) ? 10000000 : cost[source][i];
        visited[i]=0;
    }
    visited[source]=1;
    dist[source]=0;
}

int dijkstra::minimum()
{
    int mini=10000000;
    int minindex=-1;
    for (int i=0;i<4;i++)
    {
        if (!visited[i] && dist[i]<mini)
        {
            mini=dist[i];
            minindex=i;
        }
    }
    return minindex;
}

void dijkstra::updation(int cost[4][4])
{
    int u=minimum();
    if (u==-1)
        return;
    visited[u]=1;
    for (int i=0;i<4;i++)
    {
        if (visited[i]==0)
        {
        dist[i]=min(dist[i],dist[u]+cost[u][i]);
        if (dist[i]==dist[u]+cost[u][i])
            path[i]=u;
        }
    }

}
void dijkstra::shortest_path(int cost[4][4],int source)
{
    initialise(cost,source);
    for (int i=0;i<3;i++)
        updation(cost);
}

void dijkstra::print(int source)
{
    for (int i = 0; i < 4; i++)
    {
    if (i != source)
    {
    cout << "Shortest path from " << source << " to " << i << " is " << dist[i] << " through path: ";
    int j = i;
    cout << j;
    while (path[j] != source)
        {
            cout << " <- " << path[j];
            j = path[j];
        }
    cout << " <- " << source << endl;
    }
    }
}

int main()
{
int v;
int source;
int cost[4][4];
cout<<"Enter the source vertex: ";
cin>>source;
cout<<"Enter the cost matrix\n";
for (int i=0;i<4;i++)
{
    for (int j=0;j<4;j++)
    {
       cin>>cost[i][j];
    }
}
dijkstra Dijkstra;
Dijkstra.shortest_path(cost, source);
Dijkstra.print(source);
return 0;
}
