#include <iostream>
#include "Circular_Queue.h"
using namespace std;

int main()
{ 
    CircularQueue<int> q;
    int n;
    cout << "Enter size of circular queue: ";
    cin >> n;

    while (1)
    {
        cout << "\n\nPress 1 to enqueue";
        cout << "\nPress 2 to dequeue";
        cout << "\nPress 3 to display";
        cout << "\nPress 4 to exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.enqueue(n);
            break;
        case 2:
            q.dequeue(n);
            break;
        case 3:
            q.display(n);
            break;
        case 4:
            cout << "Exit!";
            return 0;
        default:
            cout << "Invalid entry please try again\n";
        }
    }
    return 0;
}
