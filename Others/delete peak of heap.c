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


void downheapify(vector<int> &heap,int idx)
{
    int leftidx=2*idx+1;
    int rightidx=2*idx+2;

    //if we are the leaf node the return
    if(leftidx>=heap.size() && rightidx>=heap.size())
        return;

    //find the largest among the children and current parent and update
    int largestidx=idx;

    //check left child
    if(leftidx<heap.size() && heap[leftidx]>heap[largestidx])
        largestidx=leftidx;
    //check right child
    if(rightidx<heap.size() && heap[rightidx]>heap[largestidx])
        largestidx=rightidx;

    //if no swapping required then return
    if(largestidx==idx)
        return;

    swap(heap[idx],heap[largestidx]);

    //recursively call for swapped part either LST or RST
    downheapify(heap,largestidx);
}

void deletepeak(vector<int> &heap)
{
    swap(heap[0],heap[heap.size()-1]);

    heap.pop_back();

    downheapify(heap,0);
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

    cout<<endl;
    deletepeak(heap);

    display(heap);

    return 0;
}
