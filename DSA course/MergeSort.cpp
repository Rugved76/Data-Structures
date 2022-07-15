#include <iostream>
using namespace std;

void merge(int *ar, int l, int r)
{
    int mid = (r + l) / 2;
    int len1 = mid - l + 1;
    int len2 = r - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainarrayindex = l;
    for (int i = 0; i < len1; i++)
    {
        first[i] = ar[mainarrayindex++];
    }

    mainarrayindex = mid + 1;

    for (int i = 0; i < len2; i++)
    {
        second[i] = ar[mainarrayindex++];
    }

    int index1 = 0;
    int index2 = 0;

    mainarrayindex = l;

    while (index1 < len1 and index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            ar[mainarrayindex++] = first[index1++];
        }
        else
        {
            ar[mainarrayindex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        ar[mainarrayindex++] = first[index1++];
    }
    while (index2 < len2)
    {
        ar[mainarrayindex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergesort(int *ar, int l, int r)
{

    if (l >= r)
    {
        return;
    }

    int mid = (l + r) / 2;

    // left side
    mergesort(ar, l, mid);
    // right side
    mergesort(ar, mid + 1, r);

    merge(ar, l, r);
}

int main()
{

    int ar[5] = {2, 5, 1, 6, 9};

    mergesort(ar, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}
