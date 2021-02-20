#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
	  SortedStack *ss = new SortedStack();
	  int n;
	  cin>>n;
	  for(int i=0;i<n;i++)
	  {
	    int k;
	    cin>>k;
	    ss->s.push(k);
	  }
	  ss->sort();
	  printStack(ss->s);
  }
}

void SortedStack :: sort()
{
   stack<int> s1;
   while(!s.empty()){
       int cur = s.top();
       s.pop();
       while (!s1.empty() && cur < s1.top()){
           s.push(s1.top());
           s1.pop();
       }
       s1.push(cur);
   }
   while(!s1.empty()){
       cout<<s1.top()<<" ";
       s1.pop();
   }
}
