class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> degrees(n,0);
        vector<vector<bool>> visit(n, vector<bool>(n,false));

        int ans = 0;

        for(auto & road : roads){
            degrees[road[0]]++;
            degrees[road[1]]++;
            visit[road[0]][road[1]] = true;
            visit[road[1]][road[0]] = true;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, (degrees[i] + degrees[j] - (visit[i][j] ? 1 : 0)));
            }
        }
        return ans;
    }
};
