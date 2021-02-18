#include <bits/stdc++.h>
using namespace std;
#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

void path(int i, int j, int m[MAX][MAX], int n, string str, vector<string >& res) {
    if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0 ) {
        return;
    }
    else if(i == n-1 && j == n-1) {
        res.push_back(str);
        return;
    }
    else {
        m[i][j]=0;
        path(i-1,j,m,n,str +'U',res);
        path(i+1,j,m,n,str +'D',res);
        path(i,j-1,m,n,str +'L',res);
        path(i,j+1,m,n,str +'R',res);
        m[i][j]=1;
    }
}

vector<string> findPath(int m[MAX][MAX], int n) {
    vector<string> res;
    path(0,0,m,n,"",res);
    sort(res.begin(), res.end());
    return res;
}
