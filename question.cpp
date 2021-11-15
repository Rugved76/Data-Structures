#include <iostream>
using namespace std;

class Stack
{
  struct node
  {
    int data;
    node* next;
  };

  node* top;                              //creating a pointer of node type

  public:
  Stack()
  {
    top=NULL;                             //intialising top to NULL as default using default constuctor
  }

  void push(int);
  int pop();
  int isempty();
  void display();
  
};

/*
Stack :: Stack()                          //also works here
{ 
  top=NULL;
}*/

void Stack :: push(int val)
{
  //node* ptr;                           //this line alone does not work 
  node* ptr = new node;                  //this is different I think, in this we create a new ptr every time this function is called
  ptr->data=val;                         //if line 36 is erased and only the 35 is used then the display function gives error along with pop fuction
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
  int val,flag=1,choice;
  while (flag==1)
  {
    cout<<"\nPress 1 to push";
    cout<<"\nPress 2 to pop";
    cout<<"\nPress 3 to display";
    cout<<"\nPress 4 to exit\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
      cout<<"Enter value to push : ";
      cin>>val;
      s.push(val);
      break;

    case 2:
      s.pop();
      break;

    case 3:
      cout<<"Stack is \n";
      s.display();
      break;

    case 4:
      flag=0;
    }

  }
  return 0;
}
