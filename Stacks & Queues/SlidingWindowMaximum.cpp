#include <bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    priority_queue<pair<int,int>> pq;
    vector<int> res;
    for(int i=0;i<n;i++) {
        while(!pq.empty() && pq.top().second <= i-k) {
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        if(i >= k-1) {
            res.push_back(pq.top().first);
        } 
    }
    return res;
    
}

int main() 
{
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    for(int i = 0;i<n;i++) {
	        cin >> arr[i];
	    }
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) {
	        cout << res[i] << " ";
      }
	    cout << endl;
	    
	}
	return 0;
}
