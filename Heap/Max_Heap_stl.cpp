//Heap//
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[6]={7,10,4,3,20,15};
    int k=2; // 2nd smallest  
    priority_queue<int> maxheap;
    for(int i=0;i<6;i++)
    {
        maxheap.push(a[i]);
        
        if(maxheap.size()>k)
        maxheap.pop();  // top get poped 
    }
    
    cout<<maxheap.top();
}