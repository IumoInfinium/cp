class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>> adj(n), cnt(n, vector<int>(26));
        vector<int> indegrees(n);
        
        for (auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            ++indegrees[e[1]];
        }
        
        vector<int> q;
        for (int i = 0; i < n; ++i)
            if (indegrees[i] == 0)
                q.push_back(i);
        
        int ans = 0, visits = 0;
        while (!q.empty()) {
            vector<int> q1;
            for (auto i : q) {
                ++visits;
                ans = max(ans, ++cnt[i][colors[i] - 'a']);
                for (auto j : adj[i]) {
                    for (auto k = 0; k < 26; ++k)
                        cnt[j][k] = max(cnt[j][k], cnt[i][k]);
                    if (--indegrees[j] == 0)
                        q1.push_back(j);
                }
            }
            swap(q, q1);
        }
        return visits != n ? -1 : ans;
    }
};
