#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) 
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str) 
{
    if (str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) 
      ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) 
          break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int diameter(struct Node* tree);

int main() 
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << diameter(root) << endl;
    }
    return 0;
}

int dia(Node* node, int& res)
{
    if(node == NULL) 
        return 0;
    int l= dia(node->left, res);
    int r =dia(node->right, res);
    res = max(res, l+ r + 1);
    return max(l,r)+1;
}

int diameter(Node* root) 
{
    int res = -1; 
    dia(root, res); 
    return res;
}
