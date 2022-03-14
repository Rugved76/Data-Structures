#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge
{
    public:
        int src, dest, weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int getParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return getParent(parent[v], parent);
}

int getMinVertex(bool *visited, int *weight, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ((minVertex == -1) || (weight[minVertex] > weight[i])))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

Edge *kruskals(Edge *edges, int n, int E)
{
    sort(edges, edges + E, compare);

    Edge *output = new Edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0, i = 0;
    while (count < (n - 1))
    {
        Edge currentEdge = edges[i];
        int srcParent = getParent(currentEdge.src, parent);
        int desetParent = getParent(currentEdge.dest, parent);

        if (srcParent != desetParent)
        {
            output[count] = currentEdge;
            count += 1;
            parent[srcParent] = desetParent;
        }
        i += 1;
    }
    return output;
}

void prims(int **edges, int n)
{
    bool *visited = new bool[n]();
    int *parent = new int[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minVertex = getMinVertex(visited, weight, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (weight[j] > edges[minVertex][j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
    delete[] parent;
    delete[] visited;
    delete[] weight;
}

int main()
{
    int n,E;
    Edge* output;
    Edge* edges = new Edge[E];
    cout<<"Enter\n";
    cout<<"1 for Kruskals\n";
    cout<<"2 for Prims\n ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter no of vertices and edges \n";
        cin>>n>>E;
        for (int i = 0; i < E; i++)
        {
            int s, d, w;
            cin >> s >> d >> w;
            edges[i].src = s;
            edges[i].dest = d;
            edges[i].weight = w;
        }
        output = kruskals(edges, n, E);

        cout<<"MST using Kruskals is as following\n";
        for (int i = 0; i < n - 1; i++)
        {
            if (output[i].src < output[i].dest)
            {
                cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
            }
            else
            {
                cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
            }
        }
        break;

    case 2:
        int e;
        cout<<"Enter no of vertices and edges\n";
        cin>>n>>e;
        int **edge = new int *[n];
        for (int i = 0; i < n; i++)
        {
            edge[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                edge[i][j] = 0;
            }
        }

        for (int i = 0; i < e; i++)
        {
            int f, s, weight;
            cin >> f >> s >> weight;
            edge[f][s] = weight;
            edge[s][f] = weight;
        }
        cout << endl;
        cout<<"The MST using Prims is as following\n";
        prims(edge, n);
        for (int i = 0; i < n; i++)
        {
            delete[] edge[i];
        }
        delete[] edge;
    }

    return 0;
}