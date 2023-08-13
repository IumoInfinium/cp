class Solution {
public:
//     int minAbsoluteDifference(vector<int>& nums, int x) {
//         int n = nums.size();
        
//         int ans = INT_MAX;
//         int dist = INT_MAX;
//         for(int i=0; i<n; i++){
//             if(i+x >= n) break;
//             for(int j=i+x; j<n; j++){
//                 int tmp = abs(nums[j] - nums[i]);
//                 if(ans > tmp){
//                     ans = tmp;
//                     // dist = abs(j-i);
//                 }
//             }
//         }
//         return ans;
//     }
        int minAbsoluteDifference(vector<int>& nums, int x) {
            int n = nums.size();
            int ans = INT_MAX;
            
            set<int> oset;
            
            for(int i=0; i<n; i++){
                if(i>=x) oset.insert(nums[i-x]);
                
                auto it = oset.lower_bound(nums[i]);
                
                if(it != oset.end()) ans = min(ans, *it - nums[i]);
                if(it != oset.begin()) ans = min(ans, nums[i] - *(--it));
            }
            return ans;
        }
};
