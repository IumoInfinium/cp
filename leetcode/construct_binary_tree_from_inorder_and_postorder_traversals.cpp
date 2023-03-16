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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;

        int n = inorder.size();
        for(int i=0; i<n; i++){
            map[inorder[i]]=i;
        }
        int postIdx = n-1;
        return makeTree(0,n-1,postorder, postIdx, map);
    }

    TreeNode* makeTree(int start, int end, vector<int>& postorder,int& postIdx, unordered_map<int,int>& map){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(postorder[postIdx--]);

        int idx = map[root->val];
        root->right= makeTree(idx+1, end, postorder,postIdx,map);
        root->left = makeTree(start, idx-1, postorder, postIdx, map);
        return root;
    }
};
