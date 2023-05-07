class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n,0),prefix(n,0);
        unordered_set<int> sett;
        int differ=0;
        for(int i=n-1; i>=0; i--){
            if(sett.count(nums[i])) suffix[i]=differ;
            else{ sett.insert(nums[i]);suffix[i] = differ++;}
        }
        sett.clear();
        int prediffer=0;
        for(int i=0; i<n;i++){
            if(sett.count(nums[i])) prefix[i]= prediffer;
            else{ sett.insert(nums[i]); prefix[i] = ++prediffer;}
        }
        // for(int i=0; i<n; i++){
        //     cout << prefix[i] <<"  " << suffix[i] << "\n";
        // }
        vector<int> ans(n,0);
        
        for(int i=0; i<n; i++){
            ans[i] = prefix[i]-suffix[i];
        }
        return ans;
    }
};
