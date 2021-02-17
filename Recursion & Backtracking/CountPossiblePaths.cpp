#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int numberOfPaths(int m, int n) {
        int cnt[m][n]; 
        for (int i = 0; i < m; i++) { 
            cnt[i][0] = 1; 
        }
  
        for (int j = 0; j < n; j++) { 
            cnt[0][j] = 1; 
        }

        for (int i = 1; i < m; i++) { 
            for (int j = 1; j < n; j++) {
                cnt[i][j] = cnt[i-1][j] + cnt[i][j-1]; 
            }
        } 
        return (cnt[m-1][n-1]); 
    }
};

int main() 
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
