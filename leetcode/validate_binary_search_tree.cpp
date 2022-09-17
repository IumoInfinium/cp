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
    private:
        vector<int> arr;
public:
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        arr.push_back(root->val);
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        inOrder(root);
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]) return false;
        }
        return true;
    }
};
