/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return vector<int>{target->val};

        vector<vector<int>> adj(501);
        makeGraph(root, NULL, adj);

        vector<int> ans;
        int vis[501]={false};

        queue<int> q;
        q.push(target->val);

        int level=0;
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                int node = q.front();
                q.pop();

                if(vis[node]) continue;
                vis[node] = 1;

                for(int nei : adj[node]) if(!vis[nei]) q.push(nei);
            }
            level++;
            if(level == k){
                while(!q.empty()) {
                    ans.push_back(q.front());
                    q.pop();
                }
            }
        }
        return ans;
    }

    void makeGraph(TreeNode *node, TreeNode* parent, vector<vector<int>>& adj){
        if(!node) return;

        if(parent != NULL) adj[node->val].push_back(parent->val);

        if(node->left){
            adj[node->val].push_back(node->left->val);
            makeGraph(node->left, node, adj);
        }
        if(node->right){
            adj[node->val].push_back(node->right->val);
            makeGraph(node->right, node, adj);
        }
        return;
    }
};
