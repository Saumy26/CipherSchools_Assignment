#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

int maxSubtreeSumRecur(TreeNode* node, int& ans)
{
    if (!node)
        return 0;
    node->val += maxSubtreeSumRecur(node->left, ans) + maxSubtreeSumRecur(node->right, ans);
    ans = max(ans, node->val);
    return node->val;
}

int maxSubtreeSum(TreeNode* root)
{
    int ans = INT_MIN;
    if (!root)
        return 0;
    maxSubtreeSumRecur(root, ans);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(7);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(-7);
    cout << maxSubtreeSum(root) << endl;
    return 0;
}
