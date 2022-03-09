#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front, rear;
    int queue[20];

public:
    CircularQueue() // Default constructor initialising front and rear to -1
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int);
    void dequeue(int);
    void display(int);
    bool validation(int);
};

void CircularQueue ::enqueue(int n)
{ 
    // To check if queue is full 
    // here front is ahead of rear
    if ((front + 1) % n == ((rear + 1) % n) + 1)
    {
        cout << "Queue is full!\n";
        return;
    }
    // If queue is empty we
    // inititalise it to 0 
    else if (front == -1)
    {
        front = 0;
    }
    // Incrementing rear by 1
    rear = (rear + 1) % n;

    cout << "Enter value :";
    cin >> queue[rear];
    cout << "Added :" << queue[rear] << endl;
}

void CircularQueue ::dequeue(int n)
{
    // Checking if queue is empty
    if (front == -1)
    {
        cout << "Queue is empty!\n";
        return;
    }
    int temp = front;

    // If queue has only one element
    // so f == r, we set f,r to -1 again
    if (front == rear)
    {
        front = rear = -1;
    }
    //deleting from front
    else
    {
        front = (front + 1) % n;
    }
    cout << "Deleted :" << queue[temp] << endl;
}

void CircularQueue ::display(int n)
{
    // If queue is empty
    if (front == -1)
    {
        cout << "Queue is empty!\n";
    }
    else if (front > rear)
    {
        cout << "CircularQueue is as following \n";
        // Since f>r we print from f to n first
        for (int i = front; i < n; i++)
        {
            cout << queue[i] << " ";
        }
        // And then from 0 to r
        for (int i = 0; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
    else
    {
        // Else print from f to r
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
}

int main()
{
    CircularQueue q;
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
