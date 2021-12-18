#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int arrSize)
{
    // Iterate to all array's element
    for(int i = 0; i < arrSize; ++i)
    {
        // Set the current element
        // as reference value
        int refValue = arr[i];

        // variable to shift the element
        // to right position
        int j;

        // Iterate through the sorted element
        // to insert the reference value
        // in right position
        for(j = i - 1; j >= 0; --j)
        {
            // if the value of the current index
            // is greater than the reference value then
            // move the current value to right side
            // otherwise, put the reference value
            // in the current index
            if(arr[j] > refValue)
                arr[j+1] = arr[j];
            else
                break;
        }

        // here's the line to put the reference value
        // in the current index (the right position)
        arr[j + 1] = refValue;
    }
}

// Quick sort function 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 


int partition(int arr[], int low ,int high)
{
    int pivot = arr[high];
    int i= (low - 1);
    for (int j = low; j <= high-1; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
        
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int arr[],int low ,int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}


// Selection sort function 

void selectionsort(int arr[], int size)
{
    int min;

    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j]<arr[min])
            {
                min = j;
            }
            
        }
        swap(arr[i],arr[min]);
    }
    
}

// Bubble sort function 

void bubblesort(int arr[])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
            
        }
        
    }
    
}


int main()
{

    int arr[] = {43, 21, 26, 38, 17, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array

    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    //quicksort(arr,0,5);
    //bubblesort(arr);
    //InsertionSort(arr, arrSize);
    //selectionsort(arr,6);
 

    cout << "Sorted array : ";

    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
        
    cout << endl;

    return 0;
}
