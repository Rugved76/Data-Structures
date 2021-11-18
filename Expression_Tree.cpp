// C++ program for expression tree
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
// An expression tree node
struct et
{
    char value;
    et* left, *right;
};
 
// A utility function to check if 'c'
// is an operator

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||  c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    return false;
}
 
// Utility function to do inorder traversal                                       
void inorder(et *t)
{
    if(t)
    {
        inorder(t->left);
        //printf("%c ", t->value);
        cout<<" "<<t->value;
        inorder(t->right);
    }
}

void preorder(et* t)
{
    if(t)
    {
        cout<<" "<<t->value;
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder_withoutRec(et* t)             //Not called yet
{
    et* temp=t;
    stack<et*> s;
    while (temp!=NULL)
    {
        s.push(temp);
        temp=temp->left;
    }
    while (!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<" "<<temp->value;
        temp=temp->right;
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
    }
    
}

void postorder(et* t)                      
{
    if(t)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<" "<<t->value;
    }
}

// A utility function to create a new node
et* newNode(char v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};
 
// Returns root of constructed tree for given
// postfix expression
et* constructTree(char postfix[])
{
    stack<et *> st;
    et *t, *t1, *t2;
 
    // Traverse through every character of
    // input expression
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);
 
            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();
 
            // make them children
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            st.push(t);
        }
    }
 
    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;
}
 
// Driver program to test above
int main()
{
    int choice;
    char postfix[30];                         // = "ab+ef*g*-";
    cout<<"Enter postfix expression : \n";
    cin>>postfix;
    et* r = constructTree(postfix);
    while (1)
    {
        cout<<"\n\nPress\n1 for infix expression \n2 for prefix expression \n3 for postfix expression \n4 exit the system\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"infix expression is \n";
            inorder(r);
            break;
        case 2:
            cout<<"Prefix expression is \n";
            preorder(r);
            break;
        case 3:
            cout<<"Postfix expression is \n";
            postorder(r);
            break;
        case 4: 
            cout<<"Exit! \n";
            return 0;
        default:
            cout<<"\nInvalid input, try again \n";
            return 0; 
           
        }

    }
    
    return 0;
}
