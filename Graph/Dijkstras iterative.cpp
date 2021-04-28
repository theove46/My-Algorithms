#include<bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            {min = dist[v], min_index = v;
            cout << "v-" << v << " min-" << min << " u-" << min_index << endl;
            }

    return min_index;
}

int printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];

    bool sptSet[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if((sptSet[v]==false) && (graph[u][v]!=0) && (dist[u] != INT_MAX) && (dist[u] + graph[u][v] < dist[v]))
                {dist[v] = dist[u] + graph[u][v];
                 cout << "dis u- " << dist[u] << " dist V-" << dist[v] << " v-" << v << " graph-" << graph[u][v] << endl;
                 }
        }
    }

    printSolution(dist);
}

int main()
{
    //cout << "How many elements: ";
    //int V;
    //cin >> V;
    int graph[V][V];
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            cin >> graph[i][j];

    dijkstra(graph, 0);
    return 0;
}

/*

0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

*/
