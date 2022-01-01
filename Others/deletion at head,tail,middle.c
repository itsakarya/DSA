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

//delete at at head
void deleteathead(node* &head)
{
    if(head==NULL)
        return;

    node* temp=head;
    head=head->next;
    delete temp;
    return;
}

//delete at tail
void deleteattail(node* &head)
{
    node* prev=NULL;
    node* temp=head;

    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    delete temp;
    prev->next=NULL;
    return;
}

void deleteatp(node* head,int p)
{
    if(p==0 || head==NULL)
        deleteathead(head);
    if(p>length(head))
        deleteattail(head);

    int jump=0;
    node* prev=NULL;
    node* forw=NULL;
    node* temp=head;
    while(jump<p-1)
    {
        prev=temp;
        temp=temp->next;
        forw=temp->next;
        jump++;
    }
    prev->next=forw;
    delete temp;
    return;
}
int main()
{
    node* head=NULL;
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,5);
    insertathead(head,6);


    deleteathead(head);

    deleteattail(head);

    deleteatp(head,2);
    print(head);
    return 0;
}
