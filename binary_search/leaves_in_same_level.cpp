/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root) {
    if(root==NULL) return true;
    queue<Tree*> q;
    q.push(root);

    int res=INT_MAX;
    int level=0;
    while(!q.empty()){
        int n=q.size();
        level++;
        while(n>0){
            Tree* tmp=q.front();
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
                if(!tmp->left->left && !tmp->left->right){
                    if(res==INT_MAX) res=level;
                    else if(res!=level) return false;
                }
            }
            if(tmp->right){
                q.push(tmp->right);
                if(!tmp->right->left && !tmp->right->right){
                    if(res==INT_MAX) res=level;
                    else if(res!=level) return false;
                }
            }
            n--;
        }
    }
    return true;
}
