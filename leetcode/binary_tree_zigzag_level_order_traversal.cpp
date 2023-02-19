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
        vector<vector<int>> ans;
        if(!root) return ans;
    
        unordered_map<int,vector<int>> lvl_map;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0}); 

        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                auto [node, lvl] = q.front();
                q.pop();
        
                lvl_map[lvl].push_back(node->val);

                if(node->left) q.push({node->left,lvl+1});
                if(node->right) q.push({node->right, lvl+1});
            }
        }

        int i=0;
        bool from=true;
        while(lvl_map.count(i)){
            if(from){
                ans.push_back(lvl_map[i]);
                from=false;
            }
            else{
                reverse(lvl_map[i].begin(),lvl_map[i].end());
                ans.push_back(lvl_map[i]);
                from=true;
            }
            i++;
        }
        return ans;
    }
};
