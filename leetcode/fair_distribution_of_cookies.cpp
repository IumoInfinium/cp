class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k,0); 
        return helper(0, dist, cookies);
    }

    int helper(int idx, vector<int>& dist, vector<int>& cookies){
        if(idx >= cookies.size()){
            int maxi = INT_MIN;
            for(int i=0; i< dist.size(); i++) maxi = max(maxi, dist[i]);
            return maxi;
        }
        int mini = INT_MAX;
        for(int i=0; i < dist.size(); i++){
            if(i>0 && dist[i-1] == dist[i]) continue;
            dist[i] += cookies[idx];
            mini = min(mini, helper(idx+1, dist, cookies));
            dist[i] -= cookies[idx];
            if(dist[i] == 0) break;
        }
        return mini;
    }
};
