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
    vector <int> leaf1, leaf2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverse(root1,leaf1);
        traverse(root2,leaf2);
        return leaf1 == leaf2;
    }

    void traverse(TreeNode* root,vector<int>& leaves){
        if(root==NULL) return ;
        traverse(root->left, leaves);
        if(root->left == NULL && root->right==NULL)
            leaves.push_back(root->val);
        traverse(root->right,leaves);        
    }
};
