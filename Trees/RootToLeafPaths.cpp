#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<vector<int>> Paths(Node *root);

Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str;)
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main() 
{
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        vector<vector<int>> paths = Paths(root);
        for(int i = 0;i<paths.size();i++) {
            for(int j = 0;j<paths[i].size();j++) {
                cout<<paths[i][j]<<" ";
            }
            cout<<"#";
        } 
        cout<<"\n";
    }
    return 0;
}

void solve(Node* root,vector<vector<int>> &ans,vector<int> &v)
{       
    if(root==NULL)
        return;
    v.push_back(root->data);
    if(!root->left && !root->right) {
        ans.push_back(v);v.pop_back();
        return;
    }
    solve(root->left,ans,v);
    solve(root->right,ans,v); v.pop_back();
    return;
} 
 
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>>ans;
    vector<int>v;
    solve(root,ans,v);
    return ans;
}
