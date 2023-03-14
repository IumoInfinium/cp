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
    int sumNumbers(TreeNode* root) {
        vector<string> values;
        dfs(root,"",values);
        return add(values);
    }
    void dfs(TreeNode* node,string curr, vector<string>& values){
        if(!node) return;
        if(!node->left && !node->right){
            values.emplace_back(curr+ to_string(node->val));
            return;
        }
        dfs(node->left,curr + to_string(node->val), values);
        dfs(node->right,curr + to_string(node->val), values);
        return;
    }

    int add(vector<string>& values){
        int ans = 0;
        for(string s : values){
            int num=0;
            int n = s.size();
            for(int i=0; i<n;i++){
                num += (s[n-i-1]-'0') * pow(10,i);
            }
            ans += num;
        }
        return ans;
    }
};
