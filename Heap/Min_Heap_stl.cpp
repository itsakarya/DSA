//Heap//
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[6]={7,10,4,3,20,15};
    int k=2; // 2nd largest  
    //priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> min_heap ;
    for(int i=0;i<6;i++)
    {
        min_heap.push(a[i]);
        
        if(min_heap.size()>k)
        min_heap.pop();  // top get poped 
    }
    
    cout<<min_heap.top();
}