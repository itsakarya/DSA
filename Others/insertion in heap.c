#include<bits/stdc++.h>
using namespace std;

//max heap implementation

void upheapify(vector<int> &heap,int idx)
{
    //if inserted element was 1st element ie the heap was empty initially
    if(idx==0)
        return;

    int parentidx=(idx-1)/2;

    //now check if up heapification needed
    if(heap[parentidx]<heap[idx])
    {
        //swap both values
        swap(heap[parentidx],heap[idx]);
        //after swapping recursively check for above parents as well
        upheapify(heap,parentidx);
    }
    else
    {
        //if upheapify not needed then just return
        return;
    }
}

void insert(vector<int> &heap,int key)
{
    heap.push_back(key);

    upheapify(heap,heap.size()-1);

}

void display(vector<int> &heap)
{
    for(int i=0;i<heap.size();i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}

int main()
{
    vector<int> heap;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insert(heap,x);
    }

    display(heap);

    return 0;
}
