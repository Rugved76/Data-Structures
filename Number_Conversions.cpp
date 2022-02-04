#include <bits/stdc++.h>
using namespace std;

string dectobin(int num)
{
    string ans ="";
    while(num>0)
    {
        ans+=(char)(num%2+'0');
        num/=2;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

void BinToDec(int n)
{
    int rem,i=0,sum=0;
    vector <int>vec;
    cout<<"Enter the binary number : ";
    cin>>n;
    while(n>0)
    {
        rem=n%10;
        n/=10;
        vec.push_back(rem*pow(2,i));
        i++;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        sum+=vec[i];
    }
    cout<<"The Decimal number is : "<<sum;
}

int bintogray(int bin)
{
    int a,b,result=0,i=0;
    while(bin!=0)
    {
        a=bin%10;
        bin/=10;
        b=bin%10;
        
        if((!a && b) || (a && !b))
        {
            result=result+pow(10,i);
        }
        i++;
    }
    return result;
}

int main()
{
    cout<<"Enter \n1 for decimal to binary\n2 for Binary to decimal \n3 for Gray code\n";
    int key;
    cin>>key;
    switch(key)
    {
        case 1:
            int n;
            cin>>n;
            cout<<dectobin(n);
            break;

        case 2:
            int x;
            BinToDec(x);
            break;

        case 3:
            int bin,gray;
            cout<<"Enter binary number : ";
            cin>>bin;
            gray=bintogray(bin);
            cout<<"The gray code of "<<bin<<" : "<<gray;
            break;

    }
    
    return 0;
}
