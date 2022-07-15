#include <iostream>
using namespace std;

// Dynamic allocation of 2D array

int main()
{
    int r, c;
    cin >> r >> c;

    int **arr = new int *[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < r; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}

/*
3
3

1 2 3 
4 5 6
7 8 9

1       2       3
4       5       6
7       8       9

*/