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


  /**
  void display(node * root)
    {
        if(root==nullptr)
        return;
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);


    }
**/
    int height(node * root)
    {
        if(root==nullptr)
        return 0;
        int ls=height(root->left); 
        int rs=height(root->right);
        return max(ls,rs)+1;

    }
  void printkthlevel(node* root,int h)
    {
        if(root==nullptr)
        return;
     if(h==1)
     {
         cout<<root->data<<" ";
     return;
     }
   printkthlevel(root->left,h-1);
   printkthlevel(root->right,h-1);
   }

void printalllevel(node* root)
 {
 int h=height(root);
 for(int i=1;i<=h;i++)
 {    
    printkthlevel(root,i);
    cout<<endl;
 }

}
// bfs // 
/*void bfs(node * root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node * f=q.front();
        cout<<f->data<<",";
        q.pop();
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
    }
    return ;
}
*/
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
int main() {

    node * root=buildtree();
    cout<<" tree str "<<endl;
    printalllevel(root);
    cout<<endl<<"bfs output :"<<endl;
    bfs(root);
}
