class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        long start = 0;
        long end = 0;
        long n = nums.size();

        vector<string> ans;
        while(start < n && end < n){
            while(end+1 < n && (long)nums[end+1] - (long)nums[end] <= 1) end++;

            if(start == end) ans.emplace_back(to_string(nums[start]));
            else ans.emplace_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            end++;
            start = end;
        }

        return ans;
    }
};
