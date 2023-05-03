class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> tmp;

        for(int i:nums1) x.insert(i);
        for(int i:nums2) y.insert(i);
        
        set_difference(x.begin(), x.end(), y.begin(), y.end(), std::back_inserter(ans[0]));
        set_difference(y.begin(), y.end(), x.begin(), x.end(), std::back_inserter(ans[1]));
        return ans;
    }

};
