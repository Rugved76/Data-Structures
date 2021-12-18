#include <iostream>
using namespace std;

class Stack
{
    struct node
    {
        int data;
        node* next;
    };

    node* top;                                 // Creating a pointer of node type

    public:

    Stack()
    {
        top=NULL;                              // Intialising top to NULL as default using default constuctor
    }

    void push(int);
    int pop();
    int isempty();
    void display();
  
};

/*
Stack :: Stack()                               // Also works here
{ 
  top=NULL;
}*/

void Stack :: push(int val)
{
    //node* ptr;                               //this line alone does not work 
    node* ptr = new node;                      //this is different I think, in this we create a new ptr every time this function is called
    ptr->data=val;                          
    ptr->next=top;
    top=ptr;
}

int Stack :: pop()
{
    if (isempty())
    {
        cout<<"Stack is empty, nothing to delete\n";
    }
    else
    {
        int val;
        node* temp;
        temp=top;
        val=temp->data;
        cout<<"Popped element is "<<top->data<<endl;
        top=top->next;
        delete(temp);
        return val;
    }
  
}

int Stack :: isempty()
{
    if (top==NULL)
    {
        return 1;
    }
    else
        return 0;
  
}

void Stack :: display()
{
    if (isempty())
    {
        cout<<"Stack is empty, nothing to display \n";
    }
    else
    {
        node* temp;
        temp=top;
        while (temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }

    }

}

int main()
{
    Stack s;
    int val,choice;
    char c;

    while (true)
    {
        cout<<"\nPress 1 to push";
        cout<<"\nPress 2 to pop";     
        cout<<"\nPress 3 to display";
        cout<<"\nPress 4 to exit\n";
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"Press y to push\n";
                cin>>c;
                while (c=='y' or c=='Y')
                {
                    cout<<"Enter value to push : ";
                    cin>>val;
                    s.push(val);
                    cout<<"Do you want to push more y/n :";
                    cin>>c;
                }
            break;
    
            case 2:
                s.pop();
                break;

            case 3:
                cout<<"Stack is \n\n";
                s.display();
                break;

            case 4:
                cout<<"Exit!! \n";
                return 0;
        }

    }

  return 0;
}
