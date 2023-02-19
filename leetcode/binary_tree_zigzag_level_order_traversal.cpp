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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool from=true;
        vector<int> tmp;
        TreeNode* node;
        
        while(!q.empty()){
            int qsize = q.size();
            tmp.resize(0);
            while(qsize--){
                node = q.front();
                q.pop();

                if(from) tmp.push_back(node->val);
                else tmp.insert(tmp.begin(),node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            from=!from;
            ans.push_back(tmp);
        }

        return ans;
    }
};
