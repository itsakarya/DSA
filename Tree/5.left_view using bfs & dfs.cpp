//TREE
/*
tree left view 
->using dfs(o(n^2))
->using bfs(0(n))
*/
#include<bits/stdc++.h>
using namespace std;
class node
{
  public:  
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=nullptr;
        right=nullptr;
    }
};
node * buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    return nullptr;
    node* root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}

void bfs(node* root)
{
    queue<node *> q;
q.push(root);  // store root 
q.push(NULL);
while(!q.empty())
{
    node * tmp=q.front();  //  fetch it through tmp.. node
 
    if(tmp==NULL)
    {
        cout<<"\n";
        q.pop();
        if(!q.empty())
        q.push(nullptr);
    }
    else
    {
    cout<<tmp->data<<" "; 
    q.pop();               
    if(tmp->left)
     q.push(tmp->left);
     if(tmp->right)
     q.push(tmp->right);
    }
}


}
//CODE
//dfs approach
void left_view(node* root,int &maxlev,int  lev)
{
    if(root==nullptr)
    return ;
    if(maxlev<lev)
    {
        // discover a new level
    cout<<root->data<<" ";
    maxlev=lev;
    }
   
    left_view(root->left,maxlev,lev + 1);
    left_view(root->right,maxlev,lev + 1);
}
//bfs approach
vector<int> leftView_using_bfs(node *root)
{
   vector<int> ans;
   if(!root) return ans;
   
   queue<node*> s;
   s.push(root);
   while(!s.empty())
   {
       
       ans.push_back(s.front()->data);
       int sz = s.size();
       while(sz--)
       {
           node* x = s.front();
           if(x->left) 
           s.push(x->left);
           if(x->right) 
           s.push(x->right);
           
           s.pop();
        }
   }
   return ans;
}
int main()
{
node * root= buildtree();
bfs(root);
int maxlev=-1;

cout<<"left view""\n";
//by dfs (a(n^2));
left_view(root,maxlev,0);
cout<<"\n";

//by bfs o(n)
vector<int> v=leftView_using_bfs(root);

for(int i=0;i<v.size();i++)
{
    cout<<v[i]<<" ";
}
}
