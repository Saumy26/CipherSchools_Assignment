#include<iostream>
#include<stack>
using namespace std;

void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
stack<int> s;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}

void push(stack<int>& s, int a){
	  s.push(a);
}

bool isFull(stack<int>& s,int n){
	  if(s.size() == n){
        return 1;
	  }
    else 
      return 0;
}

bool isEmpty(stack<int>& s){
	  if(s.size() == 0){
        return 1;
	  }
    else
      return 0;
}

int pop(stack<int>& s){
	  if(s.empty()){
        return -1;
	  }
    else{
        int top1 = s.top();
        s.pop();
        return top1;
    }
}

int getMin(stack<int>& s){
	  int min = s.top();
    s.pop();
    while(!s.empty()){
       int temp = s.top();
       s.pop();
       if(temp < min){
           min = temp;
       } 
    }
    return min;
}
