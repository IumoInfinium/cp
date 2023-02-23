class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n= capital.size();
        
        vector<pair<int,int>> prices;
        for(int i=0;i<n; i++){
            prices.push_back({capital[i],profits[i]});
        }
        // sorted to always choose the minimum capital as possible
        sort(prices.begin(), prices.end());

        // pq maintains what max profits can be chosen from current samples
        priority_queue<int> CanChoose;
        int i=0;
        while(k--){
            while(i < n && prices[i].first <= w){
                CanChoose.push(prices[i].second);
                i++;
            }
            if(CanChoose.empty()) break;        // nothing to choose from
            w += CanChoose.top();
            CanChoose.pop();
        }
        return w;
    }
};
