#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildtree(){
    int d;
    cin>>d;

    if(d==-1)
        return NULL;

    node* root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}

void printIn(node* root)
{
    if(root==NULL)
        return;
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void bfs(node* root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* fnt=q.front();
        cout<<fnt->data<<" ";
        q.pop();

        //push its child in queue
        if(fnt->left)
            q.push(fnt->left);
        if(fnt->right)
            q.push(fnt->right);
    }
    return;
}
int main()
{
    node* root=buildtree();

    printIn(root);
    cout<<endl;

    bfs(root);
    return 0;
}
