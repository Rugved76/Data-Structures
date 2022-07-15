#include <iostream>
using namespace std;

// Counting function
void print(int n)
{
    if (n == 0)
    {
        return;
        // After return the control returns
        // to the point where function was called
    }

    print(n - 1);
    cout << n << endl;
}

void bubblesort(int *ar, int n)
{
    // base case
    if (n == 0 or n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (ar[i] > ar[i + 1])
        {
            swap(ar[i], ar[i + 1]);
        }
    }
    // recursive call
    bubblesort(ar, n - 1);
}

// Function to print all permutations of string
void permutationOfString(string a, int l, int r)
{
    if (l == r)
    {
        cout << a << endl;
        return; 
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permutationOfString(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}

// Function to calculate the power of a number
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = power(a, b / 2);

    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

// Palindrome check function
bool checkpalindrome(string str, int l, int r)
{
    if (l > r)
    {
        return true;
    }
    if (str[l] != str[r])
    {
        return false;
    }
    else
    {
        l++;
        r--;
        return checkpalindrome(str, l, r);
    }
}

// Fibonacci series
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int ans = fibonacci(n - 1) + fibonacci(n - 2);

    return ans;
}

bool binarysearch(int *ar, int l, int r, int key)
{
    if (l > r)
    {
        return false;
    }
    int mid = l + (r - l) / 2;

    if (ar[mid] == key)
    {
        return true;
    }

    if (ar[mid] < key)
    {
        return binarysearch(ar, mid + 1, r, key);
    }
    else
    {
        return binarysearch(ar, l, mid - 1, key);
    }
}

void saydigit(int n)
{
    if (n == 0)
        return;
    int digit = n % 10;
    n = n / 10;

    saydigit(n);

    cout << digit << " ";
}

// Function to reverse a string
void reverse(string &s, int l, int r)
{
    if (l > r)
    {
        return;
    }
    swap(s[l], s[r]);
    l++;
    r--;

    reverse(s, l, r);
}

int main()
{
    string name="abc";
    permutationOfString(name,0,name.length()-1);
    
    return 0;
}