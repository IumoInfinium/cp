class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n = nums.size();
        int i=n-1, s=0, c=0,tmp;
        while(k>0){
            tmp = (i>-1) ? nums[i] : 0;
            s = tmp+ k%10 + c;

            if(i>-1)
                nums[i] = s%10;
            else
                nums.insert(begin(nums),s%10);
            
            if(s>9) c = 1;
            else c = 0;
            
            k/=10;
            i--;
        }
        while(c && i>-1){
            s = nums[i] + c;
            nums[i] = s%10;
            if(s>9) c=1;
            else c=0;
            i--;
        }
        if(c) nums.insert(begin(nums),1);
        return nums;
    }
};
