class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(!root) return root;
    //     if(root == p || root == q) return root;

    //     bool l = Find(root->left,p) || Find(root->left,q);
    //     bool r = Find(root->right,q) || Find(root->right,p);

    //     if(l && r) return root;
    //     else if(l && !r) return lowestCommonAncestor(root->left, p,q);
    //     else return lowestCommonAncestor(root->right,p,q);
    // }

    // bool Find(TreeNode* node, TreeNode* p){
    //     if(!node) return false;
    //     if(node== p) return true;
    //     return (Find(node->left,p) || Find(node->right,p));
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return root;
        if(root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if(!l) return r;
        else if(!r) return l;
        else return root; 
    }
};
