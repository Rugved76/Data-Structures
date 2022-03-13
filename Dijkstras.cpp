#include <iostream>
#include <iomanip>
#define SIZE 100
using namespace std;

class Graph
{
    int vertices, edges;
    int graph[SIZE][SIZE];
    int distance[SIZE];
    int visited[SIZE];

public:
    Graph() {}
    Graph(int, int);
    void create();
    void display();
    int findminvertex();
    void dijkstras();
};

Graph::Graph(int v, int e)
{
    vertices = v;
    edges = e;

    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT32_MAX;
        visited[i] = 0;
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;
    }
    distance[0] = 0;
}

void Graph::create()
{
    int source, destination, weight;
    for (int i = 0; i < edges; i++)
    {
        cout << "\nEnter the source vertex:- ";
        cin >> source;
        cout << "Enter the destination vertex:- ";
        cin >> destination;

        if (source != destination)
        {
            if (graph[source - 1][destination - 1] == 0 && graph[source - 1][destination - 1] == 0)
            {
                cout << "Enter the weight of the graph:- ";
                cin >> weight;
                graph[source - 1][destination - 1] = weight;
                graph[destination - 1][source - 1] = weight;
                cout << "Inserted edge between " << source << " and " << destination << endl;
            }
            else
            {
                cout << "\nEdge already exists. Please select a new edge" << endl;
                i--;
                continue;
            }
        }
        else
        {
            cout << "\nSource and destination cannot be the same\n";
            i--;
            continue;
        }
    }
    cout << "\n\nGraph created successfully" << endl;
}

void Graph::display()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            cout << setw(3) << graph[i][j];
        cout << endl;
    }
}

int Graph::findminvertex()
{
    int minvertex = -1;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i] && (minvertex == -1 || distance[i] < distance[minvertex]))
            minvertex = i;
    }
    return minvertex;
}

void Graph::dijkstras()
{
    for (int i = 0; i < vertices - 1; i++)
    {
        int minvertex = findminvertex();
        visited[minvertex] = 1;
        for (int j = 0; j < vertices; j++)
        {
            if (!visited[j] && graph[minvertex][j] != 0)
            {
                int dist = distance[minvertex] + graph[minvertex][j];
                if (dist < distance[j])  
                    distance[j] = dist;
            }
        }
    }
    cout << "Vertex\t"<< "Minimum Distance" << endl;
    for (int i = 0; i < vertices; i++)
        cout << i + 1 << "\t    " << distance[i] << endl;
}

int main()
{
    Graph g;
    int choice, e, v;

    while (1)
    {

        cout << "\nImplementation of Dijkstra's algorithm" << endl;
        cout << "1. Create graph" << endl;
        cout << "2. Display graph" << endl;
        cout << "3. Find shortest path using Dijkstra's algorithm" << endl;
        cout << "4. Exit the program" << endl;
        cout << "\nEnter your choice:- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the number of vertices:- ";
            cin >> v;
            cout << "\nEnter the number of edges:- ";
            cin >> e;
            g = Graph(v, e);
            g.create();
            break;

        case 2:
            g.display();
            break;

        case 3:
            g.dijkstras();
            break;

        case 4:
            return 0;

        default:
            cout << "\nError in choice, try again" << endl;
        }
    }
    return 0;
}

/*
Implementation of Dijkstra's algorithm
1. Create graph
2. Display graph
3. Find shortest path using Dijkstra's algorithm
4. Exit the program

Enter your choice:- 1

Enter the number of vertices:- 5

Enter the number of edges:- 7

Enter the source vertex:- 1
Enter the destination vertex:- 2
Enter the weight of the graph:- 10
Inserted edge between 1 and 2

Enter the source vertex:- 2
Enter the destination vertex:- 3
Enter the weight of the graph:- 50
Inserted edge between 2 and 3

Enter the source vertex:- 3
Enter the destination vertex:- 4
Enter the weight of the graph:- 20
Inserted edge between 3 and 4

Enter the source vertex:- 4
Enter the destination vertex:- 5
Enter the weight of the graph:- 60
Inserted edge between 4 and 5

Enter the source vertex:- 3
Enter the destination vertex:- 5
Enter the weight of the graph:- 10
Inserted edge between 3 and 5

Enter the source vertex:- 1
Enter the destination vertex:- 4
Enter the weight of the graph:- 30
Inserted edge between 1 and 4

Enter the source vertex:- 1
Enter the destination vertex:- 5
Enter the weight of the graph:- 100
Inserted edge between 1 and 5


Graph created successfully

Implementation of Dijkstra's algorithm
1. Create graph
2. Display graph
3. Find shortest path using Dijkstra's algorithm
4. Exit the program

Enter your choice:- 2
  0 10  0 30 100
 10  0 50  0  0
  0 50  0 20 10
 30  0 20  0 60
100  0 10 60  0

Implementation of Dijkstra's algorithm
1. Create graph
2. Display graph
3. Find shortest path using Dijkstra's algorithm
4. Exit the program

Enter your choice:- 3
Vertex  Minimum Distance
1           0
2           10
3           50
4           30
5           60

Implementation of Dijkstra's algorithm
1. Create graph
2. Display graph
3. Find shortest path using Dijkstra's algorithm
4. Exit the program

*/