#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    char s[1001];
	    cin>>s;
	    int l=strlen(s);
	    int i, j, x, a[l+1][l+1];
	    for(i=0; i<=l; i++) {
	    	for(j=0; j<=l; j++) {
	    		a[i][j]=0;
	    	}
	    }
	    for(i=1; i<=l; i++) {
	        a[i][i]=1;
	    }
	    for(i=2; i<=l; i++) {
	        for(j=1; j<=l-i+1; j++) {
	            x=j+i-1;
	            if(s[x-1]==s[j-1]) {
	                a[j][x]=a[j+1][x-1]+2;
	            }
	           else {
	            a[j][x]=max(a[j+1][x], a[j][x-1]);
	           }
	        }
	    }
	 cout<<a[1][l]<<endl;
	}
	return 0;
}
