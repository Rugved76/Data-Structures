#include <iostream>
using namespace std;

template <class T>
class Stack
{
    struct Node
    {
        T data;
        Node *next;
    };

    Node *top;

public:
    Stack();
    void push(T);
    T pop();
    T topelement();
    bool isempty();
    void display();
    void reverse();
};

template <class T>
Stack<T>::Stack()
{
    top = NULL;
}

template <class T>
void Stack<T>::push(T key)
{
    Node *newnode = new Node;
    newnode->data = key;
    newnode->next = top;
    top = newnode;
}

template <class T>
T Stack<T>::pop()
{
    if (isempty())
    {
        cout << "Stack is empty, Nothing to display\n";
    }
    else
    {
        T val;
        Node *temp = top;
        val = temp->data;
        cout << "Popped element is : " << top->data << endl;
        top = top->next;
        delete (temp);
        return val;
    }
}

template <class T>
void Stack<T>::display()
{
    if (isempty())
    {
        cout << "Stack is empty, nothing to display \n";
    }
    else
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
            cout << endl;
        }
    }
}

template <class T>
void Stack<T>::reverse()
{
    Node *prev, *curr;
    if (top != NULL)
    {
        prev = top;
        top = top->next;
        curr = top;
        prev->next = NULL;
        while (top != NULL)
        {
            top = top->next;
            curr->next = prev;
            prev = curr;
            curr = top;
        }
    }
    top = prev;
    cout << "reversed Stack is \n";
    display();
}

template <class T>
bool Stack<T>::isempty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
