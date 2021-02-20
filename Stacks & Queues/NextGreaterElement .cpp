#include<bits/stdc++.h>
using namespace std;

void nextLargerElement(long long arr[], int n)
{
    stack<long long> s;
    s.push(0);
    long long res[n];
    
    for(long long i=1; i<n; i++) {
        if(s.empty()) {
            s.push(i);
            continue;
        }
        while(!s.empty() && arr[s.top()]<arr[i]) {
            long long x=s.top();
             s.pop();
            res[x]=arr[i];
        }
        s.push(i);
    }
    while(!s.empty()) {
        long long x=s.top();
        s.pop();
        res[x]=-1;
    }
    for(long long i=0; i<n; i++) {
        cout<<res[i]<<" ";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        nextLargerElement(arr, n);
        cout<<endl;
    }
	return 0;
}
