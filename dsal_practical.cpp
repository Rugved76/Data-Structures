#include <iostream>     
using namespace std;

struct node
{
    int data;
    node *link;
};

class MyList
{
    private:
    node *head;

    public:
    MyList()
    {
        head=NULL;
    }
    void create()
    {
        node *nn,*t;
        nn=new node;
        int a;
        cout<<"\nEnter the number: ";
        cin>>a;
        nn->data=a;
        nn->link=NULL;
        if (head==NULL)
        {
            head=nn;
        }
        else
        {
            t=head;
            while (t->link!=NULL)
            {
                t=t->link;
            }
            t->link=nn;
        }
        
    } 

    void display()
    {
        cout<<"\nThe elements in the list are as follows:\n";
        node *t  = head;
        while (t!=NULL)
        {
            cout<<t->data<<"\t";
            t=t->link;
        }
    }
    void addf()
    {
        int n;
        node *nn = new node;
        cout<<"\nEnter your number: ";
        cin>>n;
        nn->data=n;
        nn->link=head;
        head=nn;
    }
    void deletef()
    {
        node *t = head;
        head =t->link;
        delete t;
        cout<<"\nFront element deleted successfully!";
    }

    void deleter()
    {
        node *prev,*t;
        t=head;
        while (t->link!=0)
        {
            prev=t;
            t=t->link;
        }
        prev->link=NULL;
        delete t;
        cout<<"\nRear element deleted successfully!";
    }
    
    void addmid()
    {
        node *nn,*prev,*t;
        int count=1;
        nn=new node;
        int p,n;
        cout<<"\nEnter the element: ";
        cin>>n;
        nn->data=n;
        cout<<"\nEnter the position where you want to add: ";
        cin>>p;
        t=head;
        while (count<p)
        {
            prev=t;
            t=t->link;
            count++;
        }
        prev->link=nn;
        nn->link=t;
    }
    void deletemid()
    {
        node *prev,*t;
        int p;
        int count=1;
        t=head;
        cout<<"\nEnter the position you want to delete: ";
        cin>>p;
        while (count<p)
        {
            prev=t;
            t=t->link;
            count++;
        }
        prev->link=t->link;
        delete t;
    }
    void search()
    {
        int a;
        node *t;
        bool flag=true;
        cout<<"\nEnter the element you want to search: ";
        cin>>a;
        t=head;
        while (t!=NULL)
        {
            if (t->data==a)
            {
                flag=false;
                break;
            }
            t=t->link;
        }
        if (flag==false)
        {
            cout<<"\nElement found!";
        }
        else if (flag==true)
        {
            cout<<"\nElement not found!";
        }
    }
};


int main()
{
    MyList ml;
    int op;
    char ch;
    while (1)
    {
        cout<<"\nPress 1 to Create a linked list\nPress 2 to add element to the front\nPress 3 to delete the element in the front\nPress 4 to delete the lement in the rear";
        cout<<"\nPress 5 to display\nPress 6 to add element in the middle\nPress 7 to delete element in the middle\nPress 8 to search for an element\nPress 9 to exit";
        cout<<"\nEnter your choice: ";
        cin >>op;
        switch(op)
        {
            case 1:
                    do
                    {
                        ml.create();
                        cout<<"\nDo you want to continue?(y/n): ";
                        cin>>ch;
                    }while (ch=='y');
            break;
            case 2:
                    ml.addf();
            break;
            case 3:
                    ml.deletef();
            break;
            case 4:
                    ml.deleter();
            break;
            case 5:
                    ml.display();
            break;
            case 6:
                    ml.addmid();
            break;
            case 7:
                    ml.deletemid();
            break;
            case 8:
                    ml.search();
            break;
            case 9:
                    exit(0);
            break;
            
            default:
                    cout<<"\nInvalid input!";
        }
    }
    return 0;
}