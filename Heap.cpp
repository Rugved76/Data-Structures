#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // Time complexity is O(Log(n)) for insert and delete
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void delete_elem()
    {
        if (size == 0)
        {
            cout << "Nothing to delete \n";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }

    // Max heap building function
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        // When indexing is 0 then
        // left = 2*i + 1 and right = 2*i + 2
        int left = 2 * i;
        int right = 2 * i + 1;
        // When indexing is 0
        // left < n && arr[largest] < arr[left]   ... same for right
        if (left <= n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if (right <= n && arr[largest] < arr[right])
        {
            largest = right;
        }
        // largest!=i means the largest has been updated
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    // Time complexity : O(nLog(n))
    void heapSort(int arr[], int n)
    {
        int size = n;
        while (size > 1)
        {
            swap(arr[size], arr[1]);
            size--;
            heapify(arr, size, 1);
        }
    }
};

int main()
{
    Heap h;

    h.insert(10);
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(4);
    h.display();

    h.delete_elem();
   
    h.display();

    return 0;
}