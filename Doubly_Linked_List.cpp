#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

// traversing a linked list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
    cout<<endl;
}

// gives length of Linked List
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void insertAtHead(Node *&tail, Node *&head, int d)
{

    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}


void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}


void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // creating a node for data
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}


void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

void reverse(Node **head_ref)
{
    Node *ptr1 = NULL;
    Node *ptr2 = *head_ref;

    // swap next and prev for all nodes of
    // doubly linked list
    while (ptr2 != NULL)
    {
        // ptr1 points to NULL 
        ptr1 = ptr2->prev;
        // ptr2 prev points to ptr2`s(head) next node
        ptr2->prev = ptr2->next;
        // ptr2`s(head) next points to ptr1(node behind head) 
        ptr2->next = ptr1;
        // shifting ptr2 to the next node
        // here prev may be confusing but remember that ptr2->prev points to the next node in sequence
        ptr2 = ptr2->prev;
    }

    // Before changing the head, check for the cases like empty
    // list and list with only one node
    // since ptr1 is always behind ptr2 and ptr1s prev points to 
    // ptr2 which is the last node in sequence so it will be set as head(head_ref)
    if (ptr1 != NULL)
    {
        *head_ref = ptr1->prev;
    }
}



int main()
{

    // Inititalization
    Node *head = NULL;
    Node *tail = NULL;

    int choice, d, pos;
    while (1)
    {
        cout<<"Press \n1 to insert at head\n2 to insert at tail\n3 to insert at position";
        cout<<"\n4 to delete node\n5 to display list\n6 to reverse list\n7 to get length\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter data :";
            cin >> d;
            insertAtHead(tail, head, d);
            break;

        case 2:
            cout<<"Enter data :";
            cin >> d;
            insertAtTail(tail, head, d);
            break;

        case 3:
            cout<<"Enter postion :";
            cin>>pos;
            cout<<"Enter data :";
            cin >> d;
            insertAtPosition(tail,head,pos,d);
            break;

        case 4:
            cout<<"Enter postion :";
            cin >> pos;
            deleteNode(pos,head);
            break;

        case 5:
            print(head);
            break;

        case 6:
            reverse(&head);
            break;
        
        case 7:
            cout<<"List has "<<getLength(head)<<" nodes\n";
            break;

        default:
            cout<<"Invalid input!";
            break;
        }
    }

    return 0;
}

/*
Alternate reversing code
Only gives the head node dont know why

void reverse(Node* head){
    Node* ptr1 = head;
    Node* ptr2 = head->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2!=NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
}

*/
