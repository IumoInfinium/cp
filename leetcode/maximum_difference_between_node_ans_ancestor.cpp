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
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }

    pair<int,int> dfs(TreeNode* root){
        if(!root) return {INT_MAX,INT_MIN};

        auto [lmin, lmax] = dfs(root->left);
        auto [rmin, rmax] = dfs(root->right);

        auto currMin=min({root->val, lmin, rmin}),
             currMax=max({root->val, lmax, rmax});
        ans = max({ans, root->val - currMin, currMax - root->val});
        return {currMin,currMax}; 
    }
};
