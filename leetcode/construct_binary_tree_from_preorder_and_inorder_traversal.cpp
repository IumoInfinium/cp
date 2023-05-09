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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;

        int preStart=0, preEnd= preorder.size()-1;
        int inStart=0, inEnd = inorder.size()-1;

        map<int,int> mp;
        for(int i=inStart; i<= inEnd; i++){
            mp[inorder[i]] = i ;
        }

        return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
    }


    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* node = new TreeNode(preorder[preStart]);
        int idx = mp[node->val];
        int n = idx - inStart;

        node->left = constructTree(preorder, preStart+1, preStart+n, inorder, inStart, idx-1,mp);
        node->right = constructTree(preorder, preStart+n+1, preEnd,inorder, idx+1, inEnd, mp);

        return node;
    }
};
