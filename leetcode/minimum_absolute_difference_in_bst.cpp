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
    int ans= INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return ans;
    }

    void helper(TreeNode* node){
        if(!node) return;
        ans = min(ans, abs(node->val - findMin(node)));
        ans = min(ans, abs(node->val - findMax(node)));
        helper(node->left);
        helper(node->right);
        return;
    } 

    int findMin(TreeNode* node){
        TreeNode* ptr = node->left;
        if(!ptr) return INT_MAX;
        while(ptr->right) ptr = ptr->right;
        return ptr->val;
    }

    int findMax(TreeNode* node){
        TreeNode* ptr = node->right;
        if(!ptr) return INT_MAX;
        while(ptr->left) ptr = ptr->left;
        return ptr->val;
    }
};
