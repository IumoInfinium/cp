class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> idx (startTime.size());

        iota(idx.begin(), idx.end(),0);
        sort(idx.begin(), idx.end(), [&](int i,int j){
            return startTime[i]>startTime[j];
        });
        map<int,int> memo;
        int maxProfit =0;
        for(auto i=0;i< idx.size(); i++){
            auto it= memo.lower_bound(endTime[idx[i]]);

            maxProfit = max(maxProfit, (it == end(memo) ? 0 : it->second) +profit[idx[i]]);
            memo[startTime[idx[i]]]= maxProfit;
        }
        return maxProfit;
    }
};
