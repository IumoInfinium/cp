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
    unordered_map<int, vector<TreeNode*>> mp;
    vector<TreeNode*> allPossibleFBT(int n) {

        vector<TreeNode*> ans;
        if(n < 1 || n%2 == 0) return ans;

        if(n == 1 ){
            ans.push_back(new TreeNode());
            mp[1] = ans; 
            return ans;
        }

        if(mp.count(n)) return mp[n];

        for(int i=1; i<n; i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);

            for(int j=0; j< left.size(); j++){
                for(int k=0; k< right.size(); k++){
                    TreeNode* node = new TreeNode();
                    node->left = left[j];
                    node->right = right[k];

                    ans.push_back(node);
                }
            }
        }
        return mp[n] = ans;
    }
};
