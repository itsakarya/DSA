#include <bits/stdc++.h>
using namespace std;
class node
{
    public :
    int data;
    node * right;
    node * left;

    node(int d)
    {
        data=d;
        left = NULL;
        right= NULL;

    }
};
    node * buildtree()
    {
        int d;
        cin>>d;
        if(d==-1)
        return NULL;
        node * root=new node(d);
        root->left=buildtree();
        root->right=buildtree();
        return root;
    }

    void display(node * root)
    {
        if(root==nullptr)
        return;
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);


    }
 

int main() {

    node * root=buildtree();
    display(root);
}
