#include<bits/stdc++.h> 
using namespace std; 
class Tree 
{
    public:
        int data;
        Tree* left = NULL,*right = NULL;
        Tree(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};
int search(int inorder[],int start,int end,int element) {
    for (int i = start; i < end;i++) {
        if (inorder[i] == element) {
            return i;
        }
    }
}
void printInorder(Tree* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    cout<<node->data<<" "; 
    printInorder(node->right); 
}
Tree* build_tree(int inorder[],int preorder[],int start,int end){
    static int index = 0;
    if (start > end) 
      return NULL;
    Tree* curr_node = new Tree(preorder[index++]);
    int x = curr_node -> data;
    if (start == end) 
        return curr_node; 
 
    int search_index = search(inorder, start, end,x); 
    curr_node->left = build_tree(inorder, preorder, start, search_index – 1); 
    curr_node -> right = build_tree(inorder, preorder, search_index + 1, end); 
    return curr_node; 
}
int main() 
{
    int in[] = { 12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87 }; 
    int pre[] = {50, 25, 12, 37, 30, 40, 75, 62, 60, 70, 87  }; 
    Tree* root = build_tree(in, pre, 0, 10); 
    printInorder(root); 
    return 0;
}
