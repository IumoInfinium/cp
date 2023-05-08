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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans; 

        vector<int> tmp;        
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});

        while(!q.empty()){
            int qsize = q.size();
            tmp.clear();
            while(qsize--){
                auto [node, lvl] = q.front();
                q.pop();

                tmp.push_back(node->val);
                if(node->left) q.push({node->left, lvl+1});
                if(node->right)q.push({node->right, lvl+1});
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
