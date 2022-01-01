#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

//calculating length of linked list
int length(node* head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
//passing a pointer variable by reference
void insertathead(node* &head,int d)
{
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}

//this is called passing by value  of head pointer
void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insertattail(node* &head,int d)
{
    if(head==NULL){
        head=new node(d);
	return;
     }
    node* tail=head;
    while(tail->next!=NULL)
        tail=tail->next;
    tail->next=new node(d);
    return;
}
//insert at position p
void insertatp(node* head,int d,int p)
{
    if(head==NULL || p==0) //case of insert at head
        insertathead(head,d);

    else if(p>length(head))  //case of insert at tail
        insertattail(head,d);

    else
    {
        //take p-1 jumps
        int jump=1;
        node* temp=head;
        while(jump<=p-1)
        {
            temp=temp->next;
            jump++;
        }
        node* n=new node(d);
        n->next=temp->next;
        temp->next=n;
    }
}
int main()
{
    node* head=NULL;
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,5);
    insertathead(head,6);

    insertattail(head,9);

    insertatp(head,10,3);

    print(head);
    return 0;
}
