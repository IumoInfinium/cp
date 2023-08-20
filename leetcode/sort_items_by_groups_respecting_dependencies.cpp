class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& grp, vector<vector<int>>& items) {
        vector<vector<int>> graph(n + m);
        vector<int> indegree(n + m, 0);

        for(int i=0; i < grp.size(); i++){
            if(grp[i] == -1) continue;
            graph[n + grp[i]].push_back(i);
            indegree[i]++;
        }

        for(int i=0; i<items.size(); i++){
            for(int ele : items[i]){
                int a = grp[ele] == -1 ? ele : n + grp[ele];
                int b = grp[i] == -1 ? i : n + grp[i];

                if(a == b){     // same grp, in order
                    graph[ele].push_back(i);
                    indegree[i]++;
                }
                else{       
                    graph[a].push_back(b);
                    indegree[b]++;
                }
            }
        }
        vector<int> ans;

        for(int i=0; i< n + m; i++){
            if(indegree[i] == 0) dfs(i, n, indegree, graph, ans);
        }
        return ans.size() == n ? ans : vector<int>{};
    }

    void dfs(int node, int n, vector<int>& indegree, vector<vector<int>>& graph, vector<int>& ans){
        if(node < n) ans.push_back(node);
        indegree[node] = -1;     // visited

        for(auto & nei : graph[node]){
            indegree[nei]--;
            if(indegree[nei] == 0) dfs(nei, n, indegree, graph, ans);
        }
        return;
    }
};
