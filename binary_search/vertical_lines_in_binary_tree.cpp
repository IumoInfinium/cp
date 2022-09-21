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
    queue<pair<Tree*,int>> q;
    q.push({root,0});
    set<int> s;
    while(!q.empty()){
        auto x=q.front();
        Tree* node=x.first;
        int xaxis=x.second;
        q.pop();
        s.insert(xaxis);
        if(node->left) q.push({node->left,xaxis-1});
        if(node->right) q.push({node->right,xaxis+1});
    }
    return s.size();
}
