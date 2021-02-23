#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        long long i, a[n];
        for(i = 0; i < n; i++) {
            cin>>a[i];
        }
        cout<< minCost(a, n)<< endl;
    }
    return 0;
}

long long minCost(long long arr[], long long n) 
{
    priority_queue <long long,vector<long long>, greater<long long>> q(arr,arr+n);
    long long int res=0;
    while(q.size()!=1) {
        long long x=q.top();
        q.pop();
        long long y=q.top();
        q.pop();
        res=res+(x+y);
        q.push(x+y);
    }
    return res;
}
