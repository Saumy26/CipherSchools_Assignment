#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

class Solution
{
    public:
    int longestUniqueSubsttr(string S)
    {
        int n = S.size();
        vector<int> arr(NO_OF_CHARS,-1);
        int j=0;
        int res = 0;
        for(int i=0; i<n; i++) {
            j = max(j, arr[S[i]]+1); 
            res = max(res, i-j+1);
            arr[S[i]] = i;
        }
        return res;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
} 
