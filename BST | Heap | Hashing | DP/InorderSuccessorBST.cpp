#include<bits/stdc++.h>
using namespace std;

struct Node 
{
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
    for(string str; iss >> str; )
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

Node* search(Node* root, int key)
{
    if (root == NULL || root->data == key)
       return root;
    if (root->data < key)
       return search(root->right, key);
    return search(root->left, key);
}

Node * inOrderSuccessor(Node *, Node* );

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        int k;
        cin>>k;
        getchar();
        Node* kNode = search( head, k );
        Node* suc = inOrderSuccessor(head, kNode);
        if( suc == NULL )
          cout<< "-1";
        else 
          cout<< suc->data;
        cout << endl;
    }
    return 1;
}

Node * inOrderSuccessor(Node *root, Node *x)
{
    if(root==NULL) {
        return NULL;
    }
    Node* y=NULL;
    if(root->data < x->data) {
        y=inOrderSuccessor(root->right, x);
    }
    else if(root->data > x->data) {
        y=inOrderSuccessor(root->left, x);
        if(y==NULL) {
            y=root;
        }
    }
    else {
        y=inOrderSuccessor(root->right, x);
    }
    return y;
}
