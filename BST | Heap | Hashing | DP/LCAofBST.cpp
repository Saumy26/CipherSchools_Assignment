#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')
          return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str;)
        ip.push_back(str);
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

Node* LCA(Node * root , int l , int h);

int main()
{
    int t;
	  scanf("%d ",&t);
    while(t--)
    {
       string s;
       int l , h;
		   getline(cin,s);
		   scanf("%d ",&l);
		   scanf("%d ",&h);
       Node* root = buildTree(s);
       cout<<LCA(root ,  l ,  h)->data<<endl;
    }
    return 1;
}
 
Node* LCA(Node *root, int n1, int n2)
{
    if(root==NULL) {
        return NULL;
    }
    if((n1<root->data)&&(n2<root->data)) {
        return LCA(root->left,n1,n2);
    }
    if((n1>root->data)&&(n2>root->data)) {
        return LCA(root->right,n1,n2);
    }
    return root;
}
