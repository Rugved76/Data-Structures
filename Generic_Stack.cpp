#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack <T> :: Stack()
{
    top=NULL;
}

template <class T>
void Stack<T> :: push(T key)
{
    Node* newnode = new Node;
    newnode->data=key;
    newnode->next=top;
    top=newnode;
}

template <class T>
T Stack<T> :: pop()
{
    T val;
    Node* temp=top;
    val=temp->data;
    cout<<"Popped element is : "<<top->data<<endl;
    top=top->next;
    delete(temp);
    return val;
}

template <class T>
void Stack<T> :: display()
{
    Node* temp=top;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        cout<<endl;
    }
    //cout<<"\n";
}

template <class T>
void Stack<T> :: reverse()           //Incomplete function does not work
{
    Node *prev,*curr;
    if (top!=NULL)
    {
        prev=top;
        top=top->next;
        curr=top;
        prev->next=NULL;
        while (top!=NULL)
        {
            top=top->next;
            curr->next=prev;
            prev=curr;
            curr=top;
        }
        
    }
    top=prev;
}