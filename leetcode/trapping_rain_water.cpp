class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int lHigh=0,rHigh=0;

        for(int l=0,r=height.size()-1; l<r;){
            if(height[l] < height[r]){
                lHigh = max(lHigh, height[l]);
                ans += lHigh - height[l++];
            }
            else{
                rHigh = max(rHigh, height[r]);
                ans += rHigh - height[r--];
            }
        }
        return ans;
    }
};
