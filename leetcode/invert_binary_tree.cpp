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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        invert(root);
        return root;    
    }

    void invert(TreeNode* node){
        if(!node) return;
        TreeNode* left = node->left;
        // TreeNode* right = node->right;
        
        node->left = node->right;
        node->right = left;
        invert(node->left);
        invert(node->right);

        return;
    }
};
