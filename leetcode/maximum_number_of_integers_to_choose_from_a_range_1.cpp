class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0; // count of the integers
        unordered_map<int,int> map;
        for(auto i : banned) map[i]++;
        
        int summ=0;
        
        int start=1;
        while(start <= n){
            if(map.count(start)){ start++; continue;}
            if(start + summ > maxSum) {start++; continue;}
            ans++;
            summ = start + summ;
            start++;
        }
        return ans;
    }
};
