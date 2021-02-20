#include<bits/stdc++.h>
using namespace std;
queue<long long int> rev(queue<long long int> q);
int main()
{
    long long int test;
    cin>>test; 
    while(test--)
    {
    queue<long long int> q; 
    long long int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<long long int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}

queue<long long int> rev(queue<long long int> q)
{
    stack<long long int>s1;
    while(!q.empty()){
      s1.push(q.front());
      q.pop();
    }
    while(!s1.empty()){
      q.push(s1.top());
      s1.pop();
    }
    return q;
}
