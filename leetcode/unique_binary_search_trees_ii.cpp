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
    vector<TreeNode*> generateTrees(int n) {
        return makeTree(1,n);
    }

    vector<TreeNode*> makeTree(int start, int end){
        vector<TreeNode*> ans;

        if(start > end){
            ans.push_back(NULL);
            return ans;
        }

        for(int p=start; p <= end; p++){
            vector<TreeNode*>  leftTree = makeTree(start, p-1);
            vector<TreeNode*> rightTree = makeTree(p+1, end);
            
            for(int i=0; i < leftTree.size(); i++){
                for(int j=0; j < rightTree.size(); j++){
                    TreeNode* root = new TreeNode(p);
                    root->left = leftTree[i];
                    root->right= rightTree[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
