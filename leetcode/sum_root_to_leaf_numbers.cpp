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
class Solution1 {
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

class Solution2{
public :
    int sumNumbers(TreeNode* root){
        int ans = 0;
        dfs(root,"", ans);
        return ans;
    }

    void dfs(TreeNode* node, string curr, int& ans){
        if(!node) return;
        if(!node->left && !node->right){
            ans += giveInt(curr + to_string(node->val));
            return;
        }
        dfs(node->left, curr + to_string(node->val), ans);
        dfs(node->right, curr + to_string(node->val), ans);
        return;
    }
    int giveInt(string s){
        int num=0;
        int n = s.size();
        for(int i=0; i<n;i++) num += (s[n-i-1]-'0') * pow(10,i);
        return num;
    }
};
class Solution{
public:
    int ans=0;
    int sumNumbers(TreeNode* root){
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode* node, int summ){
        if(!node) return;
        summ = summ*10 + (node->val);

        if(!node->left && !node->right){
            ans += summ;
            return;
        }
        dfs(node->left, summ);
        dfs(node->right, summ);
        return;
    }
};
