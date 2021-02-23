#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    if(n==1)
        return 0;
    if(arr[0]==0)
        return -1;
    int x=1, s=arr[0], m=1;
    for(int i=1; i<n-1; i++) {
        m=max(m, i+arr[i]);
        s--;
        if(s==0) {
            if(i>=m)
                return -1;
            x++;
            s=m-i;
        }
    }
    return x;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin>>arr[i];  
        }
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
