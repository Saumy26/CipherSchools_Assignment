#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0, i;
        for(i=0; i<N; i++) {
            sum += arr[i];
        }
        if(sum % 2 != 0) {
            return 0;
        }
        sum = sum/2;
        int r = N+1;
        int c = sum+1;
        int a[2][c]; 
        for(i=0; i<c; i++) {
             a[0][i] = 0;
        }
        a[0][0] = 1; 
        int cur = 1; 

        for(i=1; i<r; i++, cur^=1) {
            for(int j=1; j<c; j++) {
                    a[cur][j] = a[cur^1][j]; 
                    if(j-arr[cur^1] >= 0) 
                         a[cur][j] = max(a[cur][j], a[cur^1][j-arr[i-1]]); 
            }
        }
        return a[cur^1][c-1];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
} 
