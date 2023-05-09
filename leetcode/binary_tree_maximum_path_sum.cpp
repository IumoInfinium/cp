/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum(TreeNode* root, int& ans){
        if(!root) return 0;
        int leftTree = root->val + maxSum(root->left,ans);
        int rightTree = root->val + maxSum(root->right,ans);
        
        ans = max({ans, root->val, leftTree, rightTree, leftTree + rightTree - root->val});

        return max({leftTree, root->val, rightTree});
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxSum(root,ans);
        return ans;
    }
};

class Solution1 {
public:
    int maxSum(TreeNode* node, int& ans){
        if(!node) return 0;

        int l = max(0,maxSum(node->left, ans));
        int r = max(0,maxSum(node->right,ans));
        node->left = node->right = NULL;
        ans = max(ans, l + r + node->val);
        return node->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;  // minimum possible node value
        maxSum(root, ans);
        return ans;
    }
};
