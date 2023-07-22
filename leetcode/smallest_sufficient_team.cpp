class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        int n = (int)req.size();
        int m = (int)people.size();

        map<string, int> skill_mp;
        
        // skill mapping
        for(int i=0; i<n; i++) skill_mp[req[i]]=i;

        vector<vector<int>> ids(m);

        for(int i=0; i<m; i++){
            for(string &s : people[i]){
                ids[i].push_back(skill_mp[s]);
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(m, 10001));
        vector<vector<int>> ans(1 << n, vector<int>(m, -1));

        for(int i=0; i<m; i++) dp[0][i] = 0;

        for(int mask = 1; mask < (1 << n); mask++){
            for(int j=0; j<m; j++){
                int curr_mask = mask;

                for(int i=0; i< (int)people[j].size(); i++){
                    curr_mask = curr_mask & (~(1 << (ids[j][i])));
                }
                if(j ==0 && curr_mask != 0) continue;

                if(curr_mask == 0){
                    dp[mask][j] = 1;
                    ans[mask][j] = j;
                    continue;
                }
                if(dp[mask][j-1] <= dp[curr_mask][j-1] + 1){
                    dp[mask][j] = dp[mask][j-1];
                    ans[mask][j] = ans[mask][j-1];
                }
                else{
                    dp[mask][j] = dp[curr_mask][j-1] + 1;
                    ans[mask][j] = j;
                }
            }
        }

        vector<int> arr;
        int mask = (1 << n) -1;
        int curr = ans[mask][m-1];

        int idx = m-1;
        cout << dp[mask][idx] << endl;

        while(mask != 0 && idx >=0){
            curr = ans[mask][idx];
            if(curr != -1){
                arr.push_back(curr);
                for(int k=0; k< (int) ids[curr].size(); k++){
                    mask = mask & (~(1 << ids[curr][k]));
                }
            }
            idx--;
        }
        return arr;
    }
};
