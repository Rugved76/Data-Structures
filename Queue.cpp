#include <iostream> 
using namespace std; 

struct patient 
{
    int id; 
    string name,city,disease;
}; 

class queue 
{ 

    private: 
    int f,r; 
    patient p[50];

    public:

    queue()
    { 
        f=-1; r=-1;
    }

    void enq(int); 
    void deq(int); 
    void show(int); 
   
};
void queue::enq(int n)
{
    if((f+1)%n==((r+1)%n)+1)
{
    cout<<"Queue is full"<<endl;
    return;
}
    if(f==-1) 
    
    f=0;
    r=(r+1)%n; 

    cout<<"Enter details: \n";

    cout<<"ID:";
    cin>>p[r].id;
    
    cout<<"Name:";
    cin>>p[r].name;
    
    cout<<"City:";
    cin>>p[r].city;
    
    cout<<"Disease:";
    cin>>p[r].disease;
    
    cout<<"Record added....."<<endl;
}


void queue::deq(int n)
{
    if(f==-1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    int temp=f;
    if(f==r)
    {
        f=r=-1;
    }
    else
    {
        f=(f+1)%n;
        cout<<"Patient discharged...."<<endl;
        cout<<"Details of discharged patient:"<<endl;
        cout<<"Id:"<<p[temp].id<<"\t"<<"Name:"<<p[temp].name<<"\t"<<"City:"<<p[temp].city<<endl; 
    }
}

void queue::show(int n)
{
    cout<<"--------------------------------\n";
    if(f==-1)
{
    cout<<"No records available"<<endl;
    return;
}
    else if(f>r)
    {
        for(int i=f;i<n;i++)
        {
            cout<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
        }
    
        for(int i=0;i<=r;i++)
        {
            cout<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
        }
    }
    else
    {
        cout<<"Id\tName\tCity\tDisease"<<endl;
        for(int i=f;i<=r;i++)
        {
            cout<<p[i].id<<"\t"<<p[i].name<<"\t"<<p[i].city<<"\t"<<p[i].disease<<endl;
        }
            
    } 
    cout<<"--------------------------------\n";
}

int main()
{
    queue person;
    int n;
    
    cout<<"Enter size ";
    cin>>n;
   
    int choice;

    do
    {
        cout<<"1:Admit new Patient\n 2:Discharge patient\n 3:show all patients \n 4:Exit the system"<<endl;
        cin >> choice;
        cout<<"--------------------------------\n";
        switch (choice)
        {
        case 1:
            person.enq(n);
            break;
        case 2:
            person.deq(n);
            break;
        case 3:
            person.show(n);
            break;
        case 4:
            cout<<"Exit ";
            break;
        }

    } while (choice !=4);
    
    return 0;
}