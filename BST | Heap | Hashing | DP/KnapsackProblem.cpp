#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int a[n+1][W+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            if(j==0 || i==0) {
                a[i][j]=0;
            }
            else if(wt[i-1]>j) {
                a[i][j]=a[i-1][j];
            }
            else {
                a[i][j]=max(val[i-1]+a[i-1][j-wt[i-1]], a[i-1][j]);
            }
        }
    }
    return a[n][W];
}

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int val[n];
        int wt[n];
        for(int i=0; i<n; i++) {
            cin>>val[i];
        }
        for(int i=0; i<n; i++) {
            cin>>wt[i];
        }
        cout<<knapSack(w, wt, val, n)<<endl;
    }
	return 0;
 }
