#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    T queue[100];
    int n = 100, front = -1, rear = -1;

public:
    void Enqueue();
    void Dequeue();
    void Display();
};

template <class T>
void Queue<T> ::Enqueue()
{
    T val;
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
    Display();
}

template <class T>
void Queue<T> ::Dequeue()
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
    Display();
}

template <class T>
void Queue<T> ::Display()
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