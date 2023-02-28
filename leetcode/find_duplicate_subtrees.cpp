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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // mapping every traversal and then finding only needed traversed subtrees from it
        unordered_map< string, vector<TreeNode*>> map; 
        vector<TreeNode*> ans;

        helper(root, map);
        
        for(auto it = map.begin(); it!= map.end(); it++){
            if(it->second.size() > 1)
                ans.push_back(it->second[0]);
        }
        return ans;
    }

    string helper(TreeNode* node, unordered_map< string, vector<TreeNode*>>& map){
        if(!node) return "#";
        string s = "(" + helper(node->left, map) + to_string(node->val) + helper(node->right, map) + ")";
        map[s].push_back(node);
        return s;
    }
};
