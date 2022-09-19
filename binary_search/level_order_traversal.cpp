/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    vector<int> nodes;
    queue<Tree*> q;

    q.push(root);
    while(!q.empty()){
        int qsize=q.size();
        while(qsize--){
            Tree* curr=q.front();
            q.pop();
            nodes.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
    }
    return nodes;
}
