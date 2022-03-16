/* This program is for implementing doubly linked list
Doubly linked list is a special type of Linked List which is has two links for a given node
hence the list can be traversed in two different direction.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *prev;
// };

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList
{
    Node *head, *tail; // creating two pointer of class Node.
    int totalNodes;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        totalNodes = 0;
    }

    void append(int data)
    { // function that appends data at the end of the DLL(O(1) time complexity)
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = newNode->prev = NULL;

        if (totalNodes == 0)
        { // checking if there are any nodes or not.
            head = newNode;
            tail = newNode;
            totalNodes++;
        }
        else
        {
            tail->next = newNode; // inserting at the end.
            newNode->next = NULL;
            newNode->prev = tail;
            tail = newNode; // assigning new node as tail Note: we do this after all the pointers are set.
            totalNodes++;
        }
    }

    void preAppend(int data)
    { // function which appends the data at the beginning of the DLL;
        // O(1) time complexity
        if (totalNodes == 0)
        {
            append(data);
        }
        else
        {
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = newNode->prev = NULL;

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            totalNodes++;
        }
    }

    void insertBetween(int data, int pos)
    {
        /* to insert at the position so we can consider that
            position = 1 is a head */
        if (pos > totalNodes)
        {
            cout << "Value too large to insert" << endl;
            return;
        }
        else if (pos < 1)
        {
            cout << "Position can't be negative" << endl;
            return;
        }
        else if (pos == 1)
        {
            preAppend(data);
        }
        else if (pos == totalNodes)
        {
            append(data);
        }
        else
        {
            Node *newNode = new Node;
            newNode->data = data;
            newNode->prev = NULL;

            Node *temp = tail;
            for (int i = totalNodes - 1; i >= pos; i--)
            {
                temp = temp->prev;
            }
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            totalNodes++;
        }
    }

    void removeElement(int pos)
    {
        /* to delete at some position so we can consider that
            position = 1 is a head */
        if (pos < 1 || pos > totalNodes)
        {
            cout << "Cannot delete at this position" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            if (pos == 1)
            {
                head = head->next;
                free(temp);
                totalNodes--;
                return;
            }
            for (int i = 1; i < pos; i++)
            { // Since the pos(position) starts from 1, it should start from i = 1
                temp = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
                totalNodes--;
            }
            else
            {
                temp->prev->next = NULL;
                tail = tail->prev; // should assign new tail as the previous node of the original tail
                free(temp);
                totalNodes--;
            }
        }
    }

    void reverseList()
    {
        Node *temp = NULL;
        Node *current = head;

        while (current != NULL)
        { // swapping all next and prev pointers of nodes.
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL)
        { // checking for edge cases.
            head = temp->prev;
        }
    }

    void display()
    { // function to print the list that is being generated.
        if (head == NULL)
        {
            cout << "Please Create a Doubly Linked List" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <--> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList d;
    while (1)
    {
        cout << "\n\nPress 1 to append";
        cout << "\nPress 2 to pre append";
        cout << "\nPress 3 to insert between";
        cout << "\nPress 4 to remove element";
        cout << "\nPress 5 to display";
        cout << "\nPress 6 to reverse list";
        cout << "\nPress 7 to exit\n";

        int choice, data, pos;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin >> data;
            d.append(data);
            break;

        case 2:
            cin >> data;
            d.preAppend(data);
            break;

        case 3:
            cin >> data >> pos;
            d.insertBetween(data, pos);
            break;

        case 4:
            cin >> pos;
            d.removeElement(pos);
            break;

        case 5:
            d.display();
            break;

        case 6:
            d.reverseList();
            break;
        case 7:
            cout<<"Exit!";
            return 0;
        default:
            cout << "Invalid entry please try again\n";
        }
    }

    return 0;
}