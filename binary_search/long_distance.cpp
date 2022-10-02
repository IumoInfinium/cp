vector<int> solve(vector<int>& nums) {
    vector<int> tmp, res(nums.size());
    
    for(int i=nums.size()-1; i>=0; i--){
        int l=0, r=tmp.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(tmp[mid] >= nums[i]) r=mid;
            else l=mid+1;
        }
        res[i]=r;
        tmp.insert(tmp.begin()+r, nums[i]);
    }
    return res;
};
