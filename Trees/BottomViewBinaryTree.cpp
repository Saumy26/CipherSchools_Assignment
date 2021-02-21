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

vector <int> bottomView(Node *root);

Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
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
        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

void printBottomView(Node *root)
{
    if (root == NULL)
        return;
    int hd = 0;
    map<int, int> m;
    map<Node  *, int> mh;
    queue<Node *> q;
    mh[root] = hd;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        hd = mh[temp];
        m[hd] = temp->data;
        if (temp->left != NULL) {
            mh[temp->left] = hd-1;
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            mh[temp->right] = hd+1;
            q.push(temp->right);
        }
    }
    for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}

vector <int> bottomView(Node *root)
{
    vector <int> res;
    printBottomView(root);
    return res;
}
