// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n,0);
        vector<int> lis;  //  non-decreasing subsequence
        for(int i=0; i<n; i++){
            int curr = nums[i];

            if(lis.empty() || lis[lis.size()-1] <= curr){
                lis.emplace_back(curr);
                ans[i] = lis.size();
            }   
            else{
                int idx = upper_bound(lis.begin(), lis.end(), curr) - lis.begin();
                lis[idx] = curr;
                ans[i] = idx+1;
            }
        } 
        return ans;
    }
};
