#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    int ch;
    string r;

    Queue<string> q;

    while (1)
    {
        cout << "\n1) Enqueue element to queue" << endl;
        cout << "2) Dequeue element from queue" << endl;
        cout << "3) Display all the elements of queue" << endl;
        cout << "4) Reverse the queue" << endl;
        cout << "5) Exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cin >> r;
            q.Enqueue(r);
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.Display();
            break;
        case 4:
            q.Reverse();
            q.Display();
            break;
        case 5:
            cout << "Exit!" << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
