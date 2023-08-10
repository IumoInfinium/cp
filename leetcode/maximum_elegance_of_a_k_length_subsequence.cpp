class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        
        long long summ = 0;
        unordered_set<int> sett;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<=k; i++){
            int p = nums[n-i][0];
            int c = nums[n-i][1];
            summ += p;
            if(sett.count(c)) pq.push(p);
            sett.insert(c);
        }
        
        int sz = sett.size();
        
        long long ans = summ + 1LL * sz * sz;
        
        for(int i=k+1; i<=n && !pq.empty(); i++){
            int p = nums[n-i][0];
            int c = nums[n-i][1];
            
            if(sett.count(c)) continue;
            sett.insert(c);
            sz++;
            
            summ -= pq.top(); pq.pop();
            summ += p;
            
            ans = max(ans, summ + 1LL * sz * sz);
        }
        return ans;
    }
};
