#include <iostream>
using namespace std;

template <class T>
class CircularQueue
{
private:
    int front, rear;
    T queue[20];

public:
    // Default constructor initialising front and rear to -1
    CircularQueue();
    void enqueue(int n);
    void dequeue(int n);
    void display(int n);
};

template <class T>
CircularQueue <T> ::CircularQueue()
{
    front=-1;
    rear=-1;
}

template <class T>
void CircularQueue<T>::enqueue(int n)
{
    // To check if queue is full
    // here front is ahead of rear
    // for eg : front = 3 and rear = 2
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

template <class T>
void CircularQueue<T> ::dequeue(int n)
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
    // deleting from front
    else
    {
        front = (front + 1) % n;
    }
    cout << "Deleted :" << queue[temp] << endl;
}

template <class T>
void CircularQueue<T> ::display(int n)
{
    // If queue is empty
    if (front == -1)
    {
        cout << "Queue is empty!\n";
    }
    else if (front > rear)
    {
        cout << "CircularQueue is as following \n";
        // Since f > r we prT from f to n first
        // the part from r to f is empty
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
        // Else prT from f to r
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
}

