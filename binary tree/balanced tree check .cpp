// build a balanced binary tree ( h1-h2 <=1)
//o(n)
//bottom up (post order traversal)
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
class hbpair
{
 public :
int height;
bool balance;
};
hbpair istreebalanced(node * root)
{
    hbpair p;
    if(root==NULL)
    {
        p.height=0;
        p.balance=true;
        return p;
    }
    hbpair left=istreebalanced(root->left);
    hbpair right=istreebalanced(root->right);
    p.height=max(left.height,right.height)+1;
    if(abs(left.height-right.height)<=1 && left.balance && right.balance)
    p.balance=true;
    else
    p.balance=false;

    return p;
}

int main() {

    node * root=buildtree();
   
cout<<istreebalanced(root).balance;
    

    
}