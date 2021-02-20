#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack{
	int top;
public:
	int arr[MAX]; 
	Stack(){ 
    top = -1; 
  }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};
bool Stack::push(int x)
{
	if (top >= (MAX - 1)){
		cout << "Overflow";
		return false;
	}
	else{
		arr[++top] = x;
		cout << x << " Pushed Successfully \n";
		return true;
	}
}

int Stack::pop()
{
	if (top < 0){
		cout <<"Underflow";
		return 0;
	}
	else{
		int x = arr[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top < 0){
		cout <<"Empty Stack";
		return 0;
	}
	else{
		int x = arr[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

int main()
{
	class Stack s;
	s.push(30);
	s.push(70);
	s.push(10);
	cout <<s.pop()<<\n";
	return 0;
}
