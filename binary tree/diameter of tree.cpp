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
    // for calculating diameter we have to make 3 cases 
    //either daiametr would passes from 
    //root
    //left sub tree
    //right sub tree
    //o(n^2)
  int diameter(node * root)
  {
      if(root==NULL)
      return 0;
 
      int hls=height(root->left);
      int hrs= height(root->right);
      int op1= hls+hrs;
      int op2=diameter(root->left);
      int op3=diameter(root->right);

      return max(op1,max(op2,op3));
  }
  
  // optimised  o(n)
  
int main() {

    node * root=buildtree();
   
cout<<diameter(root);
    

    
}
