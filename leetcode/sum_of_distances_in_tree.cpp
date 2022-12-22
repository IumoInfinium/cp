class Solution {
public:
    // Approach: PreOrder and PostOrder DFS
    //   Intuition:
    //    What if given a tree, with a certain root 0?
    //    In O(N) we can find sum of distances in tree from root and all other nodes.
    //    Now for all N nodes?
    //  
    //   When we move our root from one node to its connected node, one part of nodes get closer, one the other part get further.
    //   If we know exactly hom many nodes in both parts, we can solve this problem.
    //  
    //   With one single traversal in tree, we should get enough information for it and don't need to do it again and again.
    //   Let's solve it with node 0 as root.

    // Time Complexity - O(n) -> dfs1
    //                 - O(n) -> dfs2

    // Above method is also called "re-rooting" and is common in dp-on trees!
    // count array to store number of nodes in ith subtree 
    vector<unordered_set<int>> tree;
    vector<int> ans, count;
    
    void dfs1(int root, int pre){
        for(int i : tree[root]){
            if(i == pre) continue;
            dfs1(i,root);
            count[root] += count[i];
            ans[root] += ans[i]+count[i];
        }
    }

    void dfs2(int root,int pre){
        for(int i : tree[root]){
            if(i == pre) continue;
            ans[i] = ans[root] -count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        ans.assign(n,0);
        count.assign(n,1);

        for(auto& e: edges){
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return ans;
    }
};
