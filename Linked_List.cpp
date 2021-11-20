#include <iostream>
using namespace std;

struct Node 
{
   int data;
   Node *next;
};

struct Node* head = NULL;

void insert(int new_data)                   //creates a node at the start of the Linked list
{
   Node* ptr = new Node; //(struct Node*) malloc(sizeof(struct Node));          //this also works but is lengthy
   ptr->data = new_data;
   ptr->next = head;
   head = ptr;
}

void insert_end()               //Used to insert element at the end of the linked list
{
    int data_end;
    cout<<"Enter number : ";
    cin>>data_end;
    Node* newnode = new Node;
    newnode->data=data_end;
    newnode->next=NULL; 

    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}


void display() 
{
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<<"=> "<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
 
        // If key was not present in linked list
        if (temp == NULL)
            return;
 
        // Unlink the node from linked list
        prev->next = temp->next;
 
        // Free memory
        delete temp;

    }

}
 
void delete_end()                                 //Deletes element from the end of the linked list
{
    Node* temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}

void delete_front()                               //deletes the first element in the list
{
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete(temp);
}

bool search(Node** head_ref,int key1)             //to search element in linked list, return if element exists or not
{
    Node* current = *head_ref;
    while (current!=NULL)
    {
        if (current->data==key1)
        {
            return true;
        }
        
    }
    return false;
    
}

void insert_position(int key3,int pos,Node** head_re)
{
    Node* curr=*head_re;
    Node* ptr = new Node;
    ptr->data=key3;

    while (curr!=NULL)
    {
        if(curr->data==pos)
        {
            ptr->next=curr->next;
            curr->next=NULL;
            curr->next=ptr;
        }
        curr=curr->next;
    }
    
}

int main() 
{
    int choice,x,y,val,posi;
    while (1)
    {
        cout<<"\n\nPress \n1 to insert at front\n2 to display\n3 to delete a paritcular element ";
        cout<<"\n4 to delete from front\n5 to delete from end \n6 to insert at a location\n7 to insert from end\n8 to exit\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter number to be inserted : ";
            cin>>x;
            insert(x);
            break;
        case 2:
            cout<<"the linked list is \n\n";
            display();
            break;
         
        case 3:
            cout<<"Enter element to be deleted : ";
            cin>>y;
            deleteNode(&head,y);
            break;

        case 4:
            cout<<"Deleted element from the front\n";
            delete_front();
            break;

        case 5:
            cout<<"Deleted element from the end\n";
            delete_end();
            break;

        case 6:
            cout<<"enter position and data : ";
            cin>>posi>>val;
            insert_position(val,posi,&head);
            break;
        
        case 7:
            insert_end();
            break;

        case 8:
            cout<<"Exit\n";
            return 0;
            break;
        
        default:
            cout<<"Wrong input, try again";
            return 0;
            break;
        }

    }
    
   return 0;
}