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
    bool isEmpty();
    void push(T);
    void pop();
    T  topElement();
    void display();
    void Reverse();
    void insertAtBottom(T data);
    void sortStack();
    void sortedInsert(T data);
};

template <class T>
Stack<T>::Stack()
{
    top = NULL;
}

// template <class T>
// bool Stack<T>::isEmpty()
// {
//     if (top == NULL)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

template <class T>
void Stack<T>::push(T key)
{
    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = top;
    top = newNode;
}

template <class T>
T Stack<T>::topElement()
{
    return top->data;
}

template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty!\n";
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete (temp);
    }
}

template <class T>
void Stack<T>::display()
{
    if (isEmpty())
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
bool Stack<T>::isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// template <class T>
// void Stack<T>::Reverse()
// {
//     Node *temp = NULL;
//     Node *temp2;
//     while (top != NULL)
//     {
//         temp2 = top->next;
//         top->next = temp;
//         temp = top;
//         top = temp2;
//     }
//     top = temp;
// }

template <class T>
void Stack<T>::Reverse()
{
    if (isEmpty())
    {
        return;
    }

    T val = topElement();
    pop();
    Reverse();
    insertAtBottom(val);
}

template <class T>
void Stack<T>::insertAtBottom(T data)
{
    if (isEmpty())
    {
        push(data);
        return;
    }

    T val = topElement();
    pop();

    insertAtBottom(data);

    push(val);
}

template <class T>
void Stack<T>::sortedInsert(T data)
{
    if (isEmpty() || (!isEmpty() && topElement() < data))
    {
        push(data);
        return;
    }

    T val = topElement();
    pop();
    sortedInsert(data);
    push(val);
}

template <class T>
void Stack<T>::sortStack()
{
    if (isEmpty())
    {
        return;
    }

    T val = topElement();
    pop();

    sortStack();
    sortedInsert(val);
}

/*
    Alternative reversing algorithm

template <class T>
void Stack<T>::Reverse()
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
    cout << "Reversed Stack is \n";
    display();
}

*/
