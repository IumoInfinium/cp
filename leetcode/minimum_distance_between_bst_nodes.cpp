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
    int mini = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        return mini;
    }

    void traverse(TreeNode* node){
        if(!node) return;

        mini = min(mini, abs(node->val - findMin(node)));
        mini = min(mini, abs(node->val - findMax(node)));
        traverse(node->left);
        traverse(node->right);
    }

    int findMin(TreeNode* node){
        TreeNode* tmp = node->left;
        if(!tmp) return INT_MAX;
        while(tmp->right) tmp=tmp->right;
        return tmp->val;   
    }
    int findMax(TreeNode* node){
        TreeNode* tmp = node->right;
        if(!tmp) return INT_MAX;
        while(tmp->left) tmp=tmp->left;
        return tmp->val;
    }
};
