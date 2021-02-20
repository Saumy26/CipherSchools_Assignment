#include <bits/stdc++.h>
using namespace std;

class StackNode {
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data)
{
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(StackNode* root)
{
	return !root;
}

void push(StackNode** root, int data)
{
	StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	cout << data << "Pushed \n";
}

int pop(StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	StackNode* temp = *root;
	*root = (*root)->next;
	int pop1 = temp->data;
	free(temp);

	return pop1;
}

int peek(StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main()
{
	StackNode* root = NULL;
	push(&root, 30);
	push(&root, 70);
	push(&root, 10);
	cout<<pop(&root)<< "Popped Successfully \n";
	cout<< peek(root)<<endl;
	return 0;
}
