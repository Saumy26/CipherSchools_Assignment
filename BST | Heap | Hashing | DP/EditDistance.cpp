#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    int x=s.size(), y=t.size();
		    int a[x+1][y+1];
		    for(int i=0; i<=x; i++) {
		        for(int j=0; j<=y; j++) {
		            if(i == 0) {
		                a[i][j] = j;
		            }
		            else if(j == 0) {
		                a[i][j] = i;
		            }
		            else if(s[i-1] == t[j-1]) {
		                a[i][j] = a[i-1][j-1];
		            }
		            else
		                a[i][j] = 1 + min(a[i-1][j-1], min(a[i-1][j], a[i][j-1]));
		        }
		    }
		    return a[x][y];
		}
};

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
