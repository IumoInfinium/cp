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
    // int ans=0;
    // void dfs(TreeNode* node,int depth){
    //     if(!node) return;
    //     if(depth > ans) ans=depth;
    //     dfs(node->left,depth+1);
    //     dfs(node->right,depth+1);
    //     return;
    // }
    // int maxDepth(TreeNode* root) {
    //     if(!root) return 0;
    //     dfs(root,1);
    //     return ans;
    // }

    int maxDepth(TreeNode* root, int depth=1){
        if(!root) return 0;
        return 1+ max(
            maxDepth(root->left,depth+1),
            maxDepth(root->right,depth+1));   
    }

    // int maxDepth(TreeNode* root){
    //     if(!root) return 0;
        
    //     queue<TreeNode*> q;
    //     q.push(root);

    //     int qsize,level=0;
        
    //     while(!q.empty()){
    //         qsize = q.size();
    //         while(qsize--){
    //             root = q.front();
    //             q.pop();
    //             if(root->left) q.push(root->left);
    //             if(root->right) q.push(root->right);
    //         }
    //         level++;
    //     }
    //     return level;
    // }
};
