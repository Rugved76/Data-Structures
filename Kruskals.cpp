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

// Start from 0, If you start from 1 it will not work

int main()
{
    int n, E;
    cout<<"Start from 0 \n";
    cout<<"Enter number of vertices and edges : \n";
    cin >> n >> E;
    Edge *edges = new Edge[E];

    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cout<<"Enter source, destination and weight :";
        cin >> s >> d >> w;
        edges[i].src = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }

    Edge *output = kruskals(edges, n, E);
    cout<<endl;
    cout<<"The minimum spanning tree is \n";
    cout<<"Src"<<"\t"<<"Dest"<<"\t"<<"Weight\n";
    for (int i = 0; i < n - 1; i++)
    {
        
        if (output[i].src < output[i].dest)
        {
            cout << output[i].src << "\t" << output[i].dest << "\t" << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << "\t" << output[i].src << "\t" << output[i].weight << endl;
        }
    }

    return 0;
}
