#include <iostream>
using namespace std;

class TwoStack
{

    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num)
    {
        // atleast a empty space present
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }

    void display1()
    {
        for (int i = 0; i <= top1; i++)
        {
            cout << arr[i] << endl;
        }
    }

    void display2()
    {
        for (int i = top2; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{

    int s = 8, val;
    TwoStack st(s);
    while (1)
    {
        int choice;
        cout << "Press\n1 to pop1\n2 to pop2\n3 to push1\n4 to push2\n5 to display stack1\n6 to display stack2\n\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            st.pop1();
            break;
            
        case 2:
            st.pop2();
            break;

        case 3:
            cin >> val;
            st.push1(val);
            break;

        case 4:
            cin >> val;
            st.push2(val);
            break;

        case 5:
            cout << "Stack 1 is :\n\n";
            st.display1();
            break;

        case 6:
            cout << "Stack 2 is :\n\n";
            st.display2();
            break;
        }
    }

    return 0;
}