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

vector<int> printNearNodes(Node*root,int k1 , int k2);

int main()
{
    int t;
	  scanf("%d ",&t);
    while(t--)
    {
        int k1 , k2;
        string s;
		    getline(cin,s);
		    scanf("%d ", &k1);
		    scanf("%d " , &k2);
        Node* root = buildTree(s);
        vector <int> res = printNearNodes(root, k1 ,  k2);
        for (int i=0;i<res.size();i++) cout << res[i] << " ";
        cout<<endl;
    }
    return 1;
}

void nearNodes(Node *root,int k1,int k2, vector <int> &res) 
{
    if(root == NULL) { 
        return;  
    }
    if(k1 < root->data) {  
        nearNodes(root->left, k1, k2, res);  
    }
    if(k1 <= root->data && k2 >= root->data) {  
        res.push_back (root->data);
    }
    if(k2 > root->data) {  
        nearNodes(root->right, k1, k2, res);
    }
}

vector<int> printNearNodes(Node *root, int low, int high)
{  
    vector <int> res;
    nearNodes(root, low, high, res);
    return res;
}
