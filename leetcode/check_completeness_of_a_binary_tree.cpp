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
    // bool isCompleteTree(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     vector<int> values;
    //     values.push_back(root->val);
    //     while(!q.empty()){
    //         int qsize = q.size();
    //         while(qsize--){
    //             TreeNode * curr = q.front();
    //             q.pop();

    //             if(curr->left){
    //                 values.push_back(curr->left->val);
    //                 q.push(curr->left);
    //             }
    //             else values.push_back(-1);

    //             if(curr->right){
    //                 values.push_back(curr->right->val);
    //                 q.push(curr->right);
    //             }
    //             else values.push_back(-1);
    //         }
    //     }
    //     int last = -1;
    //     for(int i=0;i<values.size();i++){
    //         if(values[i]==-1) last = i;
    //         if(last>-1 && values[i]>0) return false;
    //     }
    //     return true;
    // }

    bool isCompleteTree(TreeNode* root){
        int n = countNodes(root);
        return check(root,0,n);
    }
    int countNodes(TreeNode* node){
        if(!node) return 0;
        return 1+ countNodes(node->left) + countNodes(node->right);
    }

    bool check(TreeNode* node,int pos, int n){
        if(!node) return true;
        if(pos >= n) return false;
        bool l = check(node->left, pos*2+1,n);
        bool r = check(node->right,pos*2+2,n);
        return l && r;
    }
};
