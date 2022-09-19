/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root, int val) {
    if(!root) return false;
    if(root->val == val) return true;
    Tree* p=root;
    while(p!=NULL){
        cout<<p->val;
        if(p->val == val) return true;
        if(p->val > val) p=p->left;
        else p=p->right;
    }
    return false;
}
