#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void MaxHeapify(int a[], int i, int n) 
{
    int j;
    int temp;
    temp = a[i];                     // J is left child and J+1 is right child
    j = 2 * i;

    while (j <= n) 
    {
        if (j < n && a[j + 1] > a[j]) 
        {
            j = j + 1;              // Checking if left is bigger or right
        }
        if (temp > a[j]) 
        {
            break;
        } else if (temp <= a[j]) 
        {
            a[j / 2] = a[j];       // Swapping parent and child
            j = 2 * j;
        }
    }
    a[j / 2] = temp;               // Moving from child to parent node 
    return;
}

void Build_MaxHeap(int a[], int n) 
{
    int i;
    for (i = n / 2; i >= 1; i--) 
    {
        MaxHeapify(a, i, n);
    }
}

void Max_HeapSort(int a[], int n) 
{
    int i;
    int temp;
    for (i = n; i >= 2; i--) 
    {
        swap(a[i],a[1]);

        MaxHeapify(a, 1, i - 1);
    }
}


int main()
{
    int n ,i;

    cout<<"enter size of the array \n";
    cin>>n;
    int arr[n];

    cout<<"Enter the elements in the array\n";
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    Build_MaxHeap(arr,n);
    Max_HeapSort(arr,n);

    cout<<"Sorted in ascending order \n";

    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Sorted in descending order \n";

    for (int i = n; i >=1; i--)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
