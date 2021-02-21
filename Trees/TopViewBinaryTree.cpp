#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();
            if(c == 'L') {
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R') {
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
        topView(root);
        cout << endl;
    }
    return 0;
}

void topView(struct Node *root)
{
    if(root == NULL) {
        return;
    }
    Node *temp = NULL;
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()) {
        temp = q.front().first;
        int d = q.front().second;
        q.pop();
        if(mp.find(d) == mp.end()) {
            mp[d] = temp->data;
        }
        if(temp->left) {
            q.push({temp->left, d-1});
        }
        if(temp->right) {
            q.push({temp->right, d+1});
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->second << " ";
    }
}
