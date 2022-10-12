#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void morrisTraversal(Node *root)
{
    Node* curr=root;
    Node* pre;
    if(root==NULL) return;

    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else
        {
            //Find inorder predecur
            pre=curr->left;
            while(pre->right!=NULL and pre->right!=curr)
                pre=pre->right;

            if(pre->right==NULL)
            {
                pre->right=curr;
                curr=curr->left;
            }
            else
            {
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}

Node* bulidTree(Node* root)
{
    int d;
    cout<<"Enter data: ";
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    root=new Node(d);
    cout<<"Enter left child of "<<d<<": ";
    root->left=bulidTree(root->left);
    cout<<"Enter right child of "<<d<<": ";
    root->right=bulidTree(root->right);
    return root;
}

int main()
{
    Node* root= NULL;
    root=bulidTree(root);
    morrisTraversal(root);
}

/***********************************************************************************
Enter data: 1
Enter left child of 1: Enter data: 2
Enter left child of 2: Enter data: 4
Enter left child of 4: Enter data: -1
Enter right child of 4: Enter data: 7
Enter left child of 7: Enter data: -1
Enter right child of 7: Enter data: -1
Enter right child of 2: Enter data: 5
Enter left child of 5: Enter data: -1
Enter right child of 5: Enter data: -1
Enter right child of 1: Enter data: 3
Enter left child of 3: Enter data: -1
Enter right child of 3: Enter data: 6
Enter left child of 6: Enter data: -1
Enter right child of 6: Enter data: -1
4 7 2 5 1 3 6 
*************************************************************************************/
