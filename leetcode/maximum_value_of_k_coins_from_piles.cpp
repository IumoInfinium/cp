class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> memo(n+1, vector<int>(k+1,0));

        return helper(0,k,piles,memo);
    }

    int helper(int i, int k,vector<vector<int>>& piles, vector<vector<int>>& memo){
        if(memo[i][k] > 0) return memo[i][k];
        if(i == piles.size() || k == 0 ) return 0;

        int summ = helper(i+1,k,piles,memo);
        int curr = 0;
        for(int j=0; j< piles[i].size() && j<k; j++){
            curr += piles[i][j];
            summ = max(summ, helper(i+1, k-j-1, piles, memo) + curr);
        }
        return memo[i][k] = summ;
    }
};
