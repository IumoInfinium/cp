/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root) {
    if(!root) return 0;
    queue<Tree*> q;
    q.push(root);
    int ans=0;
    while(!q.empty()){
        Tree* tmp = q.front();
        q.pop();
        ans+= tmp->val;
        if(tmp->left) q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
    }
    return ans;
}
