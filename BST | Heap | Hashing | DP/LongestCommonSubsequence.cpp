#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;        
        string s1,s2;
        cin>>s1>>s2;      
        cout<< lcs(x, y, s1, s2)<< endl;
    }
    return 0;
}

int max(int m,int n)
{
    return (m>n)?m:n;
}

int lcs(int x, int y, string s1, string s2)
{
    int a[x+1][y+1];  
    int i, j;  
    for(i=0; i<=x; i++) {  
        for(j=0; j<=y; j++) {  
            if(i==0 || j==0) {  
                a[i][j] = 0;  
            }
            else if(s1[i-1] == s2[j-1]) {  
                a[i][j] = a[i-1][j-1] + 1;  
            }
            else {
                a[i][j] = max(a[i-1][j], a[i][j-1]);  
            }
        }  
    }  
    return a[x][y];
}
