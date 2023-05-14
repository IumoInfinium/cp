class Solution {
    int dfs(const vector<int>& nums, int round, int state, unordered_map<int, int>& mp_dp) {
        if (round > nums.size() / 2) return 0;
        if (mp_dp.count(state) > 0) return mp_dp[state];

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int picked = (1 << i) | (1 << j);
                if ((state & picked) == 0) {
                    ans = max(ans, round * __gcd(nums[i], nums[j]) + dfs(nums, round + 1, state | picked, mp_dp));
                }
            }
        }

        return mp_dp[state] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        // initial state is 0, as nothing is selected;
        // initial round is 1
        
        unordered_map<int, int> mp_dp;
        return dfs(nums, 1, 0, mp_dp);
    }
};
