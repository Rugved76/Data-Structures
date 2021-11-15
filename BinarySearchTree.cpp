#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};

class BST
{
    Node* root;
    Node* mirror;
    
    public:
    BST();
    Node* getroot();
    Node* getmirror();
    void insert();
    void insert_rec(Node*);
    void del(int);
    Node* delete_Node(Node *,int);
    void mirror_tree(Node*);
    void search(int);
    void display(Node*);
    void display_level();
    int height_tree(Node*);
	void display_leaf(Node* root);
};

BST::BST()
{
    root=NULL;
    mirror=NULL;
}

Node* BST :: getroot()
{
    return root;
}

Node* BST :: getmirror()
{
	return mirror;
}

void BST :: insert()
{
	Node* temp, *newNode;
	char ch = 'y';

	while(ch == 'y' || ch == 'Y')
	{
		newNode = new Node();
		cout<<"\nEnter data for new Node: ";
		cin>>newNode->data;
		newNode->left = newNode->right = NULL;

		if(root == NULL)
			root = newNode;
		else
		{
			temp = root;
			check:
			if(newNode->data < temp->data)
			{
				if(temp->left != NULL)
				{
					temp = temp->left;
					goto check;
				}
				else
				{
					temp->left = newNode;
				}
			}
			else if(newNode->data > temp->data)
			{
				if(temp->right != NULL)
				{
					temp = temp->right;
					goto check;
                }
				else
				{
					temp->right = newNode;
				}
            }
        }
        cout<<"\nEnter y or Y to add more Nodes: ";
        cin>>ch;
    }

}

void BST :: display_leaf(Node* root)
{
	if (root==NULL)
	{
		return;
	}
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<" ";
		return;
	}
	if (root->left)
	{
		display_leaf(root->left);
	}
	if (root->right)
	{
		display_leaf(root->right);
	}
	
}

void BST :: del(int key)
{
	root = delete_Node(root,key);
}

Node* BST :: delete_Node(Node*t ,int key)
{
    Node *temp;

	if (t == NULL)
	{
		cout<<"Not found\n";
		return t;
	}
	if (key < t->data)
	{
		t->left=delete_Node(t->left,key);
		return t;
	}
	else if(key > t->data)
	{
		t->right = delete_Node(t->right, key);
		return t;
	}
	else
	{
		if (t->left==NULL && t->right==NULL)
		{
			temp = t;
			delete temp;
			return NULL;
		}
		if (t->left==NULL)
		{
			temp = t->right;
			delete t;
			return temp;
		}
		if (t->right=NULL)
		{
			temp=t->left;
			delete t;
			return temp;
		}
		temp=t->right;
		while (temp->left!=NULL)
		{
			temp =temp->left;
		}
		t->data=temp->data;
		t->right=delete_Node(t->right,temp->data);
		return t;
	}
	return NULL;
}

void BST ::mirror_tree(Node* t)
{
	Node* temp;
	if (t!=NULL)
	{
		temp = t->left;
		t->left = t->right;
		t->right = temp;
		mirror_tree(t->left);
		mirror_tree(t->right);
	}
	else
	    return;
	
}

void BST :: search(int key)
{
	Node *temp;
	temp =root;
	check:
	if (key==temp->data)
	{
		cout<<"Found\n";
		return;
	}
	if (key<temp->data)
	{
		if (temp->left!=NULL)
		{
			temp=temp->left;
			goto check;
		}
		else
		{
			cout<<"Doesnt Ekeyist\n";
			return;
		}
		
	}
	else if(key > temp->data)
	{
		if(temp->right != NULL)
		{
			temp = temp->right;
			goto check;
		}
		else
		{
			cout<<"\nData doesnt ekeyist.";
			return;
		}
	}
	
}

void BST :: display(Node* root)
{
	if (root==NULL)
	{
		return;
	}
	else
	{
		display(root->left);
		cout<<" "<<root->data;
		display(root->right);
	}
	
}

void BST :: display_level()
{
	queue<Node*> q;
	Node* curr;
	Node* temp = root;
	if(temp == NULL)
		return;

	q.push(temp);
	q.push(NULL);

	while (q.size() > 1)
	{
		curr = q.front();
		q.pop();

		if (curr == NULL)
		{
			q.push(NULL);
			cout << "\n";
		}

		else
		{

			if(curr->left)
			q.push(curr->left);

			if(curr->right)
			q.push(curr->right);
			cout << curr->data << " ";
		}
	}
	
}

int BST::height_tree(Node *t)
{
	int hlt, hrt;
	if(t == NULL)
		return 0;
	else
	{
		hlt = height_tree(t->left) + 1;
		hrt = height_tree(t->right) + 1;
	}
	if(hlt > hrt)
		return hlt;
	return hrt;
}

int main()
{
	BST object;
	int flag=1,choice,key;
	while (flag==1)
	{
		cout<<"\n";
		cout<<"\n1. Insert.";
		cout<<"\n2. Delete.";
		cout<<"\n3. Search.";
		cout<<"\n4. Mirror Image.";
		cout<<"\n5. Display.";
		cout<<"\n6. Display Level-wise.";
		cout<<"\n7. Height of the tree.";
		cout<<"\n8. Display Leaf nodes of tree: .";
		cout<<"\n9. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		switch (choice)
		{
		case 1:
			object.insert();
			break;
		
		case 2:
		    cout<<"\nEnter data to delete: ";
			cin>>key;
			object.del(key);
			break;

		case 3:
		    cout<<"\nEnter the number to be searched: ";
			cin>>key;
			object.search(key);
			break;

		case 4:
		    cout<<"Mirror Image of tree :";
			object.mirror_tree(object.getroot());
			object.display(object.getroot());
			object.mirror_tree(object.getroot());
			break;

		case 5: 
			cout<<"\nInorder traversal of tree: ";
			object.display(object.getroot());
			break;

		case 6: 
			cout<<"\nLevel-Order traversal of tree: \n";
			object.display_level();
			break;

		case 7: 
			cout<<"\nHeight of the tree: "<<object.height_tree(object.getroot());
			break;

		case 8:
		    cout<<"Leaf nodes of tree are: ";
			object.display_leaf(object.getroot());
			break;
		case 9:
		    cout<<"Exit !";
			flag=0;
			break;
		}

	}

	return 0;
}
