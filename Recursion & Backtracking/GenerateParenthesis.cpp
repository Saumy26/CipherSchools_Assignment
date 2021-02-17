#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

void generate(int l, int r, string &str, vector<string> &res) 
{
        if (l == 0 && r == 0) {
            res.push_back(str);
            return;
        }
        if (l > 0) {
            str.push_back('(');
            generate(l-1, r, str, res);
            str.pop_back();
        }
        if (r > l) {
            str.push_back(')');
            generate(l, r-1, str, res);
            str.pop_back();
        }
}

vector<string> AllParenthesis(int n) 
{
    vector<string> res;
    string str;
    generate(n, n, str, res);
    return res;
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> result = AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
