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
    void bfs(TreeNode* node, int sum ,vector<int>& path, vector<vector<int>>& res){
        if(!node) return;
        path.push_back(node->val);
        if(!node->left && !node->right && node->val==sum) res.push_back(path);
        bfs(node->left, sum-node->val, path,res);
        bfs(node->right,sum-node->val, path,res);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        bfs(root,targetSum, path, res);
        return res;
    }
};
