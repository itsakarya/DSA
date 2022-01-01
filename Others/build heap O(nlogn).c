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
}


// input= 11
// 100 40 43 5 2 9 20 10 20 35 38

// output=
// 100 40 43 20 38 9 20 10 5 35 2
