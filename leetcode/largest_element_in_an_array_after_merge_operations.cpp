#define ll long long
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        
        ll q = nums[n-1];
        
        for(int i= n-2; i>=0; i--){
            ll p = nums[i];
            
            if(p <= q){
                q = p  + q;
                ans = max(ans, q);
            }
            else{
                ans = max(ans, q);
                q = p;
            }
        }
        return q;
    }
};
