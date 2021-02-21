#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node* node) 
{
    if (node == NULL)
      return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() 
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

Node *build(int in[],int post[],int str,int end,int *i)
{
    if(str>end) {
        return NULL;
    }
    else {
        int a=post[*i];
        *i=*i-1;
        int b;
        for(b=str; b<=end; b++) {
            if(in[b]==a) {
                break;
            }
        }
        struct Node *root=new Node(a);
        root->right=build(in,post,b+1,end,i);
        root->left=build(in,post,str,b-1,i);
        return root;
    }
}

Node *buildTree(int in[], int post[], int n) 
{
    int i=n-1;
    return build(in,post,0,n-1,&i);
}
