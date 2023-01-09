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
    // vector<int> res;
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(!root) return res;
    //     res.push_back(root->val);
    //     preorderTraversal(root->left);
    //     preorderTraversal(root->right);
    //     return res;
    // }

    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode *curr=root;
        while(curr || !st.empty()){
            while(curr){
                res.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            curr=curr->right;
        }
        return res;
    }
};
