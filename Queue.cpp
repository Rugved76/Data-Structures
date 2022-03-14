#include <iostream>
using namespace std;

class Queue
{
private:
    int queue[100], n = 100, front = -1, rear = -1;

public:
    void Enqueue();
    void Dequeue();
    void Display();
};

void Queue ::Enqueue()
{
    int val;
    if (rear == n - 1)
        cout << "Queue Overflow" << endl;
    else
    {
        if (front == -1)
            front = 0;
        cout << "Insert the element in queue : " << endl;
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}
void Queue ::Dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow ";
        return;
    }
    else
    {
        cout << "Element deleted from queue is : " << queue[front] << endl;
        front++;
        ;
    }
}
void Queue ::Display()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are : ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main()
{
    int ch;

    Queue q;
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