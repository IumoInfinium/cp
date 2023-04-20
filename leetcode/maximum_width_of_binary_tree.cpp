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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        int ans = 1;
        while(!q.empty()){
            int qsize=q.size();

            int start_idx = q.front().second;
            int end_idx = q.back().second;

            ans = max(ans, end_idx - start_idx + 1);

            while(qsize--){
                auto [node, curr] = q.front();
                q.pop();
                
                int curr_idx = curr - start_idx;
                
                if(node->left) q.push({node->left, (long long)2*curr_idx +1});
                if(node->right)q.push({node->right,(long long)2*curr_idx +2});
            }
        }
        return ans;
    }
};
