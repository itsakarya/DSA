#include<bits/stdc++.h>
using namespace std;

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


void display(vector<int> &heap)
{
    for(int i=0;i<heap.size();i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}



void buildheap(vector<int> &heap)
{
    for(int i=0;i<heap.size();i++)
        upheapify(heap,i);
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



void deletekey(vector<int> &heap,int idx)
{
    //update key with max priority value
    heap[idx]=INT_MAX;

    //upheapify node to reach at the top
    upheapify(heap,idx);

    //delete the peak node
    deletepeak(heap);
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
        heap.push_back(x);
    }

    buildheap(heap);
    display(heap);


    int idx;
    cin>>idx;

    deletekey(heap,idx);

    display(heap);
}


// input= 11
// 100 40 43 5 2 9 20 10 20 35 38
//2

// output=
// 100 40 43 20 38 9 20 5 10 2 35
//100 40 35 20 38 9 20 5 10 2

