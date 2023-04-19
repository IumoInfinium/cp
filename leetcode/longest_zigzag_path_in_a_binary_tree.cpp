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
    int ans=0;
    int longestZigZag(TreeNode* root) {
        dfs(root->left,false);
        dfs(root->right,true);
        return ans;
    }

    void dfs(TreeNode* node, bool dir, int count=1){
        if(!node) return;
        ans = max(ans,count);
        if(!dir){
            dfs(node->left, false,1);  // start a spawner from here again
            dfs(node->right, true,count+1);
        }
        else{
            dfs(node->left, !dir, count+1);
            dfs(node->right, true, 1);  // start a spawner from here again
        }
    }
};
