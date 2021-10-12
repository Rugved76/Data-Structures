#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

node *top = NULL;

bool isempty()
{
    if (top==NULL)
    {
        return true;
    }
    else
        return false;
}

void push(int val)
{
    node *ptr = new node();
    ptr->data=val;
    ptr->link=top;
    top = ptr;
}

void pop()
{
    if (isempty())
    {
        cout<<"Stack is empty \n";
    }
    else
    {
       node *ptr = top;
        cout<<"Popped element is "<<top->data <<endl;
        top = top -> link;
        //cout<<"Popped element is "<<top->data <<endl;
        delete(ptr);
        
    }
}

void display()
{
    if (isempty())
    {
        cout<<"Stack is empty \n";
    }
    else
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout<<temp->data<<endl;
            temp = temp -> link;
        }
        
    }

    
}

int main()
{
    int choice,flag=1,val;

    while (flag ==1)
    {
        cout<<"\n Press 1 to push \n 2 to pop \n 3 to display \n 4 to Exit ";
        cin>>choice;
    
    switch (choice)
    {
    case 1:
        cin>>val;
        push(val);
        break;

    case 2:
        pop();
        break;

    case 3:
        display();
        break;

    case 4:
        flag = 0;
        break;
    }
    }

    return 0;
    
}