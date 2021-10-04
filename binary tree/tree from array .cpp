// build a balanced binary tree using an array
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
 /*   node * buildtree()
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
*/
    void display(node * root)
    {
        if(root==nullptr)
        return;
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);


    }
class hbpair
{
 public :
int height;
bool balance;
};
node * buildtreefromarray(int a[],int s, int e)
{
if(s>e)
return NULL;
int m=(s+e)/2;
node * root=new node(a[m]);
root->left=buildtreefromarray(a,s,m-1);

root->right=buildtreefromarray(a,m+1,e);
return root;


} 
int main() {

   int a[8]={1,2,3,4,5,6,7,8};
 
display(buildtreefromarray(a,0,7));
    

    
}