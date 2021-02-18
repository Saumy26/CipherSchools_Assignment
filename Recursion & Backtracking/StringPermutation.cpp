#include <iostream>
using namespace std;

void perm(int start, int end, string S){
    if(start==end) {
        cout<<S<<" ";
    }
    for(int i=start; i<=end; i++)
    {
        swap(S[start], S[i]);
        perm(start+1, end, S);
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string S;
	    cin>>S;
	    for(int i=0; i<S.size(); i++) {
	        for(int j=i+1; j<S.size(); j++) {
	            if(S[i] > S[j]) {
	                swap(S[i], S[j]);
	            }
	        }
	    }
	    perm(0, S.size()-1, S);
	    cout<<endl;
	}
	return 0;
}
