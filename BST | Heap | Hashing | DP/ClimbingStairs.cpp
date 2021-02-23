#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int countWays(int);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin>>m;
        cout<<countWays(m)<<endl; 
    }
    return 0;
}

int countWays(int m)
{
    int a[m+1];
    a[1]=1;
    a[2]=2;
    for(int i=3; i<=m; i++) {
        a[i]=(a[i-1] + a[i-2])%mod;
    }
    return a[m];
}
