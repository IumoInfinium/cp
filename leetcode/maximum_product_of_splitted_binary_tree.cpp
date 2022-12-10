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
    // long ans = 0, total = 0, s;
    // int maxProduct(TreeNode* root) {
    //     if(!root) return 0;
    //     total = summ(root);
    //     summ(root);
    //     return ans % (int)(1e9 + 7);
    // }

    // int summ(TreeNode* root){
    //     if(!root) return 0;
    //     s = root->val + summ(root->left) + summ(root->right);
    //     ans = max(ans, s*(total-s));
    //     return s;
    // }

    int findSum(TreeNode* node, vector<int>& sums){
        if(!node) return 0;
        auto lsum = findSum(node->left, sums);
        auto rsum = findSum(node->right,sums);
        auto summ = lsum + rsum + node->val;
        sums.push_back(summ);
        return summ;
    }
    int maxProduct(TreeNode* root){
        int mod = 1e9+7;
        vector<int> sums;
        auto total = findSum(root,sums);
        long maxProd = 0;
        for( long val : sums)
            maxProd = max(maxProd, val* (total-val));
        return maxProd % mod;
    }
};

