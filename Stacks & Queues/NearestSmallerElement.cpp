#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:	
	void immediateSmaller(int *arr, int n) 
  {
	    for(int i=0;i<n-1;i++) {
            if(arr[i+1]<arr[i]) {
              arr[i]=arr[i+1];
            }
            else
              arr[i]=-1;
        }
        arr[n-1]=-1;
	}
};

int main() 
{
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
