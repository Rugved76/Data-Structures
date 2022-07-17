#include <iostream>
using namespace std;

struct node
{
      int data;
      node *link;
};

class MyList
{
private:
      node *head;

public:
      MyList()
      {
            head = NULL;
      }
      void create()
      {
            node *Node, *t;
            Node = new node;
            int a;
            cout << "\nEnter the number: ";
            cin >> a;
            Node->data = a;
            Node->link = NULL;
            if (head == NULL)
            {
                  head = Node;
            }
            else
            {
                  t = head;
                  while (t->link != NULL)
                  {
                        t = t->link;
                  }
                  t->link = Node;
            }
      }

      void display()
      {
            cout << "\nThe elements in the list are as follows:\n";
            node *t = head;
            while (t != NULL)
            {
                  cout << t->data << "--> ";
                  t = t->link;
            }
      }

      void addf()
      {
            int n;
            node *Node = new node;
            cout << "\nEnter your number: ";
            cin >> n;
            Node->data = n;
            Node->link = head;
            head = Node;
      }

      void delete_front()
      {
            node *t = head;
            head = t->link;
            delete t;
            cout << "\nFront element deleted successfully!";
      }

      void delete_rear()
      {
            node *prev, *t;
            t = head;
            while (t->link != 0)
            {
                  prev = t;
                  t = t->link;
            }
            prev->link = NULL;
            delete t;
            cout << "\nRear element deleted successfully!";
      }

      void addmid()
      {
            node *Node, *prev, *temp;
            int count = 1;
            Node = new node;
            int p, n;
            cout << "\nEnter the element: ";
            cin >> n;
            Node->data = n;
            cout << "\nEnter the position where you want to add: ";
            cin >> p;
            temp = head;
            while (count < p)
            {
                  prev = temp;
                  temp = temp->link;
                  count++;
            }
            prev->link = Node;
            Node->link = temp;
      }

      void deletemid()
      {
            node *prev, *temp;
            int p;
            int count = 1;
            temp = head;
            cout << "\nEnter the position you want to delete: ";
            cin >> p;
            while (count < p)
            {
                  prev = temp;
                  temp = temp->link;
                  count++;
            }
            prev->link = temp->link;
            delete temp;
      }

      void search()
      {
            int a;
            node *temp;
            bool flag = false;
            cout << "\nEnter the element you want to search: ";
            cin >> a;
            temp = head;
            while (temp != NULL)
            {
                  if (temp->data == a)
                  {
                        flag = true;
                        break;
                  }
                  temp = temp->link;
            }
            if (flag)
            {
                  cout << "\nElement found!";
            }
            else 
            {
                  cout << "\nElement not found!";
            }
      }

      void reverse()
      {
            node *temp = NULL;
            node *temp2;
            while (head != NULL)
            {
                  // temp2 will point to the next of head
                  temp2 = head->link;
                  // head will point to temp
                  // temp is NULL
                  head->link = temp;
                  // temp will point to head
                  temp = head;
                  // head will shift to the next node of head(temp2)
                  head = temp2;
            }
            // setting the head as last element
            head = temp;
      }
};

int main()
{
      MyList obj;
      int op;
      char ch;
      while (1)
      {
            cout << "\n\nPress 1 to Create a linked list\nPress 2 to add element to the front\nPress 3 to delete the element in the front\nPress 4 to delete the lement in the rear";
            cout << "\nPress 5 to display\nPress 6 to add element in the middle\nPress 7 to delete element in the middle\nPress 8 to search for an element\nPress 9 to reverse list\nPress 10 to exit";
            cout << "\nEnter your choice: ";
            cin >> op;
            switch (op)
            {
            case 1:
                  do
                  {
                        obj.create();
                        cout << "\nDo you want to continue?(y/n): ";
                        cin >> ch;
                  } while (ch == 'y');
                  break;
            case 2:
                  obj.addf();
                  break;
            case 3:
                  obj.delete_front();
                  break;
            case 4:
                  obj.delete_rear();
                  break;
            case 5:
                  obj.display();
                  break;
            case 6:
                  obj.addmid();
                  break;
            case 7:
                  obj.deletemid();
                  break;
            case 8:
                  obj.search();
                  break;
            case 9:
                  obj.reverse();
                  break;
            case 10:
                  return 0;
                  break;

            default:
                  cout << "\nInvalid input!";
            }
      }
      return 0;
}
