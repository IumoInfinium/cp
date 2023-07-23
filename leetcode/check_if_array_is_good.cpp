class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return false;
        
        vector<int> base(n+1,0);
        
        for(int x : nums){
            if(x > n) return false;
            else base[x]++;
        }
        
        for(int i=1; i<n; i++){
            if(i <n -1 && base[i] != 1) return false;
            if( i == n-1 && base[i] != 2) return false;
        }
        return true;
    }
};
