// stack using array

#include <bits/stdc++.h>
#define SIZE 128
using namespace std;

class Stack
{
    // declaring values
    int top;
    int *arr;

public:
    // initailizing values
    Stack()
    {
        top = -1;
        arr = new int[SIZE];
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // function to push data into stack-[array]
    void push(int data)
    {
        // Overflow check in case the limit exceeds
        if (top >= SIZE - 1)
        {
            cout << "Stack Overflows!" << endl;
            return;
        }
        // increment the counter and add the data
        top ++;
        arr[top] = data;
    }

    // function pops the top most element
    void pop()
    {
        // checking whether the Stack is empty! or not
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        // decrementing top
        top--;
    }

    // function used to peek onto the top most element
    int peek()
    {
        // checking if Stack is empty!
        if (isEmpty())
        {
            cout << "Stack is empty!";
            return 0;
        }
        return arr[top];
    }

    void display()
    {
        // looping over the stack conditionally
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        // if Stack is empty! then else block is executed
        else
        {
            cout << "The Stack elements are: " << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            cout << endl;
        }
        
    }

    int topElement()
    {
        return arr[top];
    }

    void reverse()
    {
        int l = 0;
        int r = top;
        while (l <= r)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
        r = top;
        l = 0;
    }

    void insertAtBottom(int data)
    {
        for (int i = top; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        top++;
        arr[0] = data;
    }

    void sortStack()
    {
        // sort(arr,arr+top); does not work for unknown reason
        sort(arr, arr + top + 1);
    }
};

int main()
{
    Stack s;

    s.push(3);
    s.push(33);
    s.push(333);
    s.display();
    s.pop();
    cout<<s.peek();

    return 0;
}
