int solve(vector<int>& nums){
    int summ=0;
    for(int i: nums) summ+=i;
    int n=(nums.size()-1)*(nums.size())/2;
    return summ-n;
}
