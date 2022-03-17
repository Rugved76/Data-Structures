#include <iostream>
using namespace std;

template <class T>
class Queue
{
    public:
        int n,front,rear;
        T queue[100];
        Queue();
        void Enqueue(T val);
        void Dequeue();
        void Display();
        int Top();
        bool IsEmpty();
};

template <class T>
Queue<T> :: Queue(){
    n = 100;
    front = -1;
    rear = -1;
}

template <class T>
void Queue<T>::Enqueue(T val)
{
    if (rear == n - 1)
        cout << "Queue Overflow" << endl;
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = val;
    }
}

template <class T>
int Queue<T>::Top(){
    return front;
}

template <class T>
void Queue<T>::Dequeue()
{
    if (IsEmpty())
    {
        cout << "Queue Underflow ";
        return;
    }
    else
    {
        front++;
    }
}

template <class T>
bool Queue<T> :: IsEmpty(){

    if (front == -1  or front > rear)
        return 1;
    else 
        return 0;

}

template <class T>
void Queue<T>::Display()
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
