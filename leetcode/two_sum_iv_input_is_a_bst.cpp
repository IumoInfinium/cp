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
    vector<int> nums;
    void inorder(TreeNode* node){
        if(!node) return;
        inorder(node->left);
        nums.push_back(node->val);
        inorder(node->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int mid,l=0,h=nums.size()-1;
        while(l<h){
            if(nums[l]+nums[h]==k) return true;
            else if(nums[l]+nums[h]<k) l++;
            else h--;
        }
        return false;
    }
};
