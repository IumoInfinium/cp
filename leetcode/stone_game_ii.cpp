class Solution {
public:
    // int dp[105][105][2];
    // int stoneGameII(vector<int>& piles) {
    //     // true -> alice's turn 
    //     // false -> bob's turn
    //     memset(dp, -1, sizeof(dp));
    //     int n = piles.size();
    //     return helper(0, 1, piles, n, 0);
    // }

    // int helper(int idx, int M, vector<int>& piles,int n, int turn){
    //     if(idx >= piles.size()) return 0;

    //     if(dp[idx][M][turn] != -1) return dp[idx][M][turn];

    //     int ans;
    //     if(!turn){
    //         // alice's turn
    //         ans = 0;
    //         int tmp =0;

    //         for(int i=0; i<2*M; i++){
    //             if(idx+i >= n) break; 
    //             tmp += piles[idx+i];
    //             ans  = max(ans, tmp + helper(idx+i+1, max(M, i+1), piles, n, 1));
    //         }
    //         // return ans;
    //     }
    //     else{
    //         // bob's turn -> minimize it!
    //         ans = INT_MAX;
    //         for(int i=0; i<2*M; i++){
    //             if(idx+i >= n) break; 
    //             ans = min(ans, helper(idx+i+1, max(M, i+1), piles, n, 0));
    //         }
    //         // return ans;
    //     }
    //     dp[idx][M][turn] = ans;
    //     return ans;
    // }

    // ============================================
    int dp[101][101];

    int stoneGameII(vector<int>& piles){
        memset(dp, -1, sizeof(dp));

        return helper(0, 1, piles);
    }

    int helper(int idx, int m, vector<int>& piles){
        int n = piles.size();

        if(idx >= n) return 0;
        if(dp[idx][m] != -1) return dp[idx][m];

        int ans=INT_MIN;
        int count=0;
        int summ=0;

        for(int i=idx; i< min(n, idx + 2*m); i++){
            count++;
            summ += piles[i];

            int nextM = max(m, count);
            int bobScore = INT_MAX;

            for(int j=1; j<=2*nextM; j++){
                bobScore = min(bobScore, helper(i+j+1, min(n,max(nextM, j)), piles));
            }
            ans = max(ans, bobScore + summ);
        }
        return dp[idx][m] = ans;
    }
};
