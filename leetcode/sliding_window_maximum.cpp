class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int p = 0;
        int q = k-1;

        multiset<int> mset;

        for(int i=p; i<=q; i++) mset.insert(nums[i]);
        auto it = mset.end();
        ans.push_back(*(--it));

        for(int i=q+1; i<n; i++){
            mset.insert(nums[i]);
            auto t = mset.find(nums[i-k]);
            mset.erase(t);
            it = mset.end();
            ans.push_back(*(--it));
        }
        return ans;
    }
};
