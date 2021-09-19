#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct student
{
    int roll;
    float SGPA;
    string name;
};
class room 
{
    
    student s[50];
    int n;

    public:
    void setdata();
    void showdata();
    void get_data();
    int getn();
    void search_sgpa();                  // searchs SGPA and returns students details with that SGPA
    void sort_rollno();        
    void sort_sgpa();                    // sorts the SGPA
    int searchname();                    // binary search method
    void alphabetically();               // insertion sort
    void sort_sgpa_quick(int , int );    // quick sort 
    void toppers_list();
    
};

void room::setdata()
{
    cout<< "enter size : \n";
    cin>>n;
    cout << "enter student detail : \n ";
    cout << "Name, Roll no and SGPA \n";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].roll >> s[i].SGPA;
    }
}

void room :: showdata()
{
    cout << "Roll No  " << " Name " << " SGPA \n";
    for (int i = 0; i < n; i++)
    {
        cout << " "<<s[i].roll << " "<<s[i].name <<" " << s[i].SGPA<< endl;
    }
    
}

int room :: getn()
{
    return n;
}

void room :: search_sgpa()
{
    float sample;
    cout<< " \n Enter SGPA to be searched : \n";
    cin>> sample;
    cout << "Roll No  " << " Name " << " SGPA \n";
     
    for (int i = 0; i < n; i++)
    {
        if (s[i].SGPA==sample)
        {
            cout<< s[i].roll << "          " << s[i].name << "      " << s[i].SGPA<< endl;
        }
        
    }
    cout<<"\n";
    
}

void room :: sort_rollno()
{
    cout<<"Sorted according to roll no \n";
     for (int i = 0; i < n-1; i++)
    {
        for (int  j = 0; j < n-1-i; j++)
        {
            if (s[j].roll>s[j+1].roll)
            {
                swap(s[j],s[j+1]);
            }
            
        }
        
    }
    cout << "Roll No " << " Name " << " SGPA \n";
    
     for (int i = 0; i < n; i++)
    {
        cout<< s[i].roll<<"           "<<s[i].name<<"         "<<s[i].SGPA<<"  "<<endl;
    }

}

void room :: toppers_list()
{
    sort_sgpa_quick(0,getn()-1);
    cout << "Roll No " << " Name " << " SGPA \n";
    for (int  i = 0; i < n; i++)
    {
         cout << s[n - (i + 1)].roll << "\t" << s[n - (i + 1)].name << "\t" << s[n - (i + 1)].SGPA<< endl;
    }
    
}

void room :: sort_sgpa()                               
{
    cout<< " Sorted SGPA is : \n";
    for (int i = 0; i < n-1; i++)
    {
        for (int  j = 0; j < n-1-i; j++)
        {
            if (s[j].SGPA>s[j+1].SGPA)
            {
                swap(s[j],s[j+1]);
            }
            
        }
        
    }
    cout << "Roll No " << " Name " << " SGPA \n";
    for (int i = 0; i < n; i++)
    {
        cout<< s[i].roll<<" "<<s[i].name<<" "<<s[i].SGPA<<" "<<endl;
    }

}


int room :: searchname()
{
    alphabetically();
    cout<< "Enter name :\n";
    string a ;
    cin >> a;
    int low = 0 , high = getn(), mid;
    while ((s[high-1].name).compare(s[low].name)>=0)
    {
        mid = (low + high)/2;
        if ((a).compare(s[mid].name)>0)
        {
            low = mid + 1;
        }
        else if ((a).compare(s[mid].name)<0)
        {
            high = mid -1 ;
        }
        else
        {
            return mid;
        }
        
    }
   
}
void room :: get_data()
{
    int r = searchname();
    cout << "Roll No  " << " Name " << " SGPA \n";
    cout<<s[r].roll<<"       "<<s[r].name <<"  "<<s[r].SGPA<< " ";
    cout<<endl;
}

void room :: alphabetically()   //insertion sort method
{
    int i,j;
    string temp;
    for (int i = 0; i < n; i++)
    {
        temp = s[i].name;
        j=i-1;
        while (j>=0 && s[j].name>temp)
        {
            s[j+1].name=s[j].name;
            j--;
        }
        s[j+1].name = temp;
        
    }
    cout << "Alphabetically sorted names : \n";
    cout << "Roll No " << " Name " << " SGPA \n";
    showdata();
    
}
void room ::sort_sgpa_quick(int l, int r)    //quick sort method
{
     if (l >= r)
        return;
    int i = l;
    int j = r + 1;
    struct student prec;
    int p = s[l].SGPA;
    prec = s[l];
    while (1)
    {
        do
        {
            i++;
        } while (s[i].SGPA < p);
        do
        {
            j--;
        } while (s[j].SGPA > p);
        if (i >= j)
            break;
        struct student temp;
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
    s[l] = s[j];
    s[j] = prec;
    sort_sgpa_quick(l, j - 1);
    sort_sgpa_quick(j + 1, r);

}

int main()
{
    room person;
    while (1)
    {
     
    cout<<"press \n 1 for setting data \n 2 to showdata \n 3 to search sgpa \n 4 to sort roll no \n 5 to sort sgpa \n 6 to search name \n 7 to arrange names alphabetically \n 8 to find toppers"<<endl;
    int num;
    cin>>num;
    switch (num)
    {
    case 1:
        person.setdata();
        break;
    
    case 2:
        person.showdata();
        break;
    case 3:
        person.search_sgpa();
        break;
    case 4:
        person.sort_rollno();
        break;
    case 5:
        person.sort_sgpa();
        break;
    case 6:
        person.get_data();
        break;
    case 7:
        person.alphabetically();
        break;
    case 8:
        person.toppers_list();
        break;
    
    }
    
  }
    return 0;
}