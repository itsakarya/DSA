#include<bits/stdc++.h>
using namespace std;

int main()
{
    //array
    int arr[5];
    
    for(int i=0;i<5;i++)
        cin>>arr[i];
    
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
    
    cout<<arr[3]<<endl;
    
    //vector
    vector<int> v;
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    
    cout<<endl;
    
    //pop front back
    v.pop_back();
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    
    cout<<endl;
    
    // v.clear();
    // for(int i=0;i<v.size();i++)
    //     cout<<v[i]<<" ";
    
    cout<<v.front()<<" "<<v.back()<<endl;
    
    //map
    map<int,int> mp;
    
    int nm;
    cin>>nm;
    
    for(int i=0;i<nm;i++)
    {
        int x;
        cin>>x;
        mp[i]=x;
    }
    
    for(int i=0;i<nm;i++)
        cout<<mp[i]<<" ";
    cout<<endl;
    map<int,int> ::iterator it;
    
    it=mp.begin();
    
    while(it!=mp.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    
    //queue
    queue<int> q;
    
    q.push(1);
    q.push(3);
    q.push(5);
    
    // while(!q.empty())
    // {
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
//    cout<<endl;
    
    cout<<q.size()<<" "<<q.back()<<endl;
    
    
    //stack
    stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    
    cout<<s.size()<<endl;
    
    //set
    set<int> s1;
    
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(2);
    s1.insert(6);
    s1.insert(0);
    
    set<int> ::iterator its;
    its=s1.begin();
    
    while(its!=s1.end())
    {
        cout<<*its<<" ";
        its++;
    }
    
    
    
}