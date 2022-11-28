class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        set<int> wins;
        map<int,int> loss;
        for(auto &m : matches){
            wins.insert(m[0]);
            loss[m[1]]++;
        }
        for(int p : wins) if(loss.find(p) == end(loss)) ans[0].push_back(p);
        for(auto [p,l] : loss) if(l==1) ans[1].push_back(p);
        return ans;
    }
};
