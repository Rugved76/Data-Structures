#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    int ch;

    Queue <string> q;
    while (1)
    {
        cout << "1) Enqueue element to queue" << endl;
        cout << "2) Dequeue element from queue" << endl;
        cout << "3) Display all the elements of queue" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            q.Enqueue();
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.Display();
            break;
        case 4:
            cout << "Exit!" << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
