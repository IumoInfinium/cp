class Solution {
public:
//     bool canSplitArray(vector<int>& nums, int m) {
//         if(nums.size() == 1 || nums.size() == 2) return 1;
//         return helper(0, nums.size()-1, m, nums);
//     }
    
    
//     bool helper(int start, int end, int m , vector<int>& nums){
//         if(start > end) return true;
        
//         for(int p=1; p< nums.size()-1; p++){
//             if(p - start == 1){
//                 bool t = helper(start+p, end, m, nums);
//                 if(t) return true;
//             }
//             else{
//                 int x = 0;
//                 for(int i=start; i<p; i++) x+= nums[i];
//                 bool t =false;
//                 if(x >= m) t =  helper(start+p, end, m, nums);
//                 if(t) return true;
//             }
//         }
//         return false;
//     }
    
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        if((n == 1 && m>=1) || n == 2) return true;
        
        for(int i=0; i<n-1; i++){
            int x = nums[i] + nums[i+1];
            if(x >= m) return true;
        }
        return false;
    }
    
};
