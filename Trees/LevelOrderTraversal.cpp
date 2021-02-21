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
vector<int> levelOrder(struct Node* node);

void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
}

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
  scanf("%d ",&t);
  while (t--)
  {
    string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}

vector<int> levelOrder(Node* node)
{
  queue<Node *> q;
  vector<int> res;
  if(node)
    q.push(node);
  while(q.size()) {
      int s=q.size();
      while(s--){
          res.push_back(q.front()->data);
          if(q.front()->left)
          q.push(q.front()->left);
          if(q.front()->right)
          q.push(q.front()->right);
          q.pop();
      }
  }
  return res;
}
