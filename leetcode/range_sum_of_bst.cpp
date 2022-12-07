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

    // // searchs complete binary tree
    // int sum=0;
    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     if(!root) return 0;
    //     if(root->val >=low && root->val <=high )sum += root->val;
    //     rangeSumBST(root->left,low,high);
    //     rangeSumBST(root->right,low,high);
    //     return sum;    
    // }

    // seaches only set of nodes in tree
    int sum = 0;
    int rangeSumBST(TreeNode *root, int low ,int high){
        if(!root) return 0;
        if(root->val >= low && root->val <=high) sum += root->val;
        if(root->left!= NULL && root->left->val < low) rangeSumBST(root->left->right,low,high);
        else rangeSumBST(root->left,low,high);

        if(root->right!= NULL && root->right->val > high) rangeSumBST(root->right->left,low,high);
        else rangeSumBST(root->right,low,high);

        return sum;
    }
};
