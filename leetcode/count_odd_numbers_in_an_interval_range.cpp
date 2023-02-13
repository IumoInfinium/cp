class Solution {
public:
    int countOdds(int low, int high) {
        int ans=0;
        while(low<=high){
            if(low==high && low&1){
                ans++;
                low++; high--;
                continue;
            }
            if(low&1) ans++;
            if(high&1) ans++;
            low++; high--;
        }
        return ans;
    }
};
