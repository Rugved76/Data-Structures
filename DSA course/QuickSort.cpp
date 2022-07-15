#include <iostream>
using namespace std;

int partition(int ar[],int l ,int r){
    int pivot  = ar[l];

    int cnt=0;
    for (int  i = l+1; i <= r; i++)
    {
        if(ar[i]<=pivot){
            cnt++;
        }
    }
    
    // placing the pivot at right position
    int pivotindex = l+cnt;
    swap(ar[pivotindex],ar[l]);

    // left and right part swapped
    int i=l,j=r;

    while (i<pivotindex and j>pivotindex)
    {
        while (ar[i]<pivot)
        {
            i++;
        }
        while (ar[j]>pivot)
        {
            j--;
        }
        
        if(i<pivotindex and j>pivotindex){
            swap(ar[i++],ar[j--]);
        }
    }
    
}

void quicksort(int ar[],int l,int r){

    // base case
    if(l>=r){
        return;
    }

    int p = partition(ar,l,r);
    
    // left recursion call
    quicksort(ar,l,p-1);
    // right recursion call
    quicksort(ar,p+1,r);
}

int main()
{
    int ar[5]={2,4,1,6,9};

    quicksort(ar,0,4);

    for (int i = 0; i < 5; i++)
    {
        cout<<ar[i]<<" ";
    }
    

    return 0;
}