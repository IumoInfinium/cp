class Solution {
public:
    // int ans = 0 ;
    // int tallestBillboard(vector<int>& rods) {

    //     int summ=0;
    //     for(int i : rods) summ += i;

    //     helper(rods.size()-1, 0, 0, summ, rods);
    //     return ans;
    // }


    // void helper(int idx, int rod1, int rod2, int remains, vector<int>& nums){
    //     if(idx < 0){
    //         if (rod1 == rod2 && rod1 > ans) ans = rod1;
    //         return;
    //     }
    //     if(rod1 + rod2 + remains <= 2* ans || abs(rod1 - rod2) >= remains) return;

    //     helper(idx-1, rod1 + nums[idx], rod2, remains - nums[idx], nums);
    //     helper(idx-1, rod1, rod2 + nums[idx], remains - nums[idx], nums);
    //     helper(idx-1, rod1, rod2, remains - nums[idx], nums);
    // }


    // int tallestBillboard(vector<int>& rods){
    //     int mid_sum = accumulate(begin(rods), end(rods), 0)/2;
    //     vector<vector<int>> dp(rods.size(), vector<int>(mid_sum+1 , -2));

    //     return max(0, helper(0, 0, 0, mid_sum, rods, dp));
    // }

    // int helper(int idx, int rod1, int rod2, int mid_sum, vector<int>& rods, vector<vector<int>>& dp){
    //     if(rod1 > mid_sum || rod2 > mid_sum) return -1;
    //     if(idx >= rods.size()) return rod1 == rod2 ? rod1 : -1;

    //     if(dp[idx][ abs(rod1 - rod2)] == -2){
    //         dp[idx][abs(rod1 - rod2)] = max(-1,
    //                 max({
    //                     helper(idx + 1, rod1, rod2 , mid_sum, rods, dp),
    //                     helper(idx + 1, rod1 + rods[idx], rod2, mid_sum, rods, dp),
    //                     helper(idx + 1, rod1, rod2 + rods[idx], mid_sum, rods, dp)
    //                 }) - max(rod1, rod2));
    //     }
    //     return dp[idx][abs(rod1 - rod2)]  +  (dp[idx][abs(rod1 - rod2)] == -1  ? 0 :  max(rod1, rod2)); 
    // }

    int dp[21][2*5000+1];
    int tallestBillboard(vector<int>& rods) {   
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 0, rods)/2;
    }

    int helper(int idx, int rod1, int rod2, vector<int>& rods){
        if(idx >= rods.size()) return rod1 == rod2 ? 0 : -10000;

        if(dp[idx][abs(rod1 - rod2)] != -1) return dp[idx][abs(rod1 - rod2)];
        int rod1_take = rods[idx] + helper(idx+1, rod1 + rods[idx], rod2, rods);
        int rod2_take = rods[idx] + helper(idx+1, rod1, rod2 + rods[idx], rods);
        int not_take =  0 + helper(idx+1, rod1, rod2, rods);
        
        return dp[idx][abs(rod1 - rod2)] = max(not_take, max(rod1_take, rod2_take));
    }
};
