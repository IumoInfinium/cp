class Solution {
public:
    // better memory, but not good runtime.
    // int countOdds(int low, int high) {
    //     int ans=0;
    //     while(low<=high){
    //         if(low==high && low&1){
    //             ans++;
    //             low++; high--;
    //             continue;
    //         }
    //         if(low&1) ans++;
    //         if(high&1) ans++;
    //         low++; high--;
    //     }
    //     return ans;
    // }
    
    // better runtime, but not good memory anymore.
    int countOdds(int a, int b){
        if(!(a&1) && !(b&1)) return (b-a)/2;
        else return 1+(b-a)/2;
    }
};
