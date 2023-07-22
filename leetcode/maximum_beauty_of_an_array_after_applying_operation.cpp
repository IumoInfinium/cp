class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 1;
        int maxLen = 100001;
        
        int n = nums.size();
        
        vector<int> freq(maxLen, 0);
        for (int num : nums) {
            freq[num]++;
        }
        vector<int> prefix(maxLen, 0);
        vector<int> suffix(maxLen, 0);

        prefix[0] = 0;
        for (int i = 1; i < maxLen; ++i) {
            prefix[i] = prefix[i - 1] + freq[i - 1];
        }

        suffix[maxLen - 1] = 0;
        for (int i = maxLen - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + freq[i + 1];
        }

        for (int i = 0; i < maxLen; i++) {
            int high = i + k > maxLen - 1 ? 0 : suffix[i + k];
            int low = i - k < 0 ? 0 : prefix[i - k];
            ans = max(ans, n - low - high);
        }

        return ans;
    }
};
