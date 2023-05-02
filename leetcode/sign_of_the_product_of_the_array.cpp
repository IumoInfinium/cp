class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product=1 ;
        for(int i: nums){
            if(i == 0) return 0;
            product *= i < 0 ? -1 : 1;
        }
        if(product <0) return -1;
        return 1;
    }
};
