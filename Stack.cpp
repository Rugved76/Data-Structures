#include <iostream>
#include "Stack.h"
using namespace std;


int main()
{
    Stack <int> s;
    int val, choice;
    char c;

    while (true)
    {
        cout << "\nPress 1 to push";
        cout << "\nPress 2 to pop";
        cout << "\nPress 3 to display";
        cout << "\nPress 4 to reverse stack";
        cout << "\nPress 5 to exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Press y to push\n";
            cin >> c;
            while (c == 'y' or c == 'Y')
            {
                cout << "Enter value to push : ";
                cin >> val;
                s.push(val);
                cout << "Do you want to push more y/n :";
                cin >> c;
            }
            break;

        case 2:
            s.pop();
            break;

        case 3:
            cout << "Stack is \n\n";
            s.display();
            break;

        case 4:
            s.reverse();
            break;
                
        case 5:
            cout << "Exit!! \n";
            return 0;
        }
    }

    return 0;
}
