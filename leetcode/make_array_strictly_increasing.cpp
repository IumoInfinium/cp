class Solution {
public:
    int dp[2001][2001];
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        memset(dp, -1, sizeof(dp));
        
        // set<int> sett;
        // for(int i=0; i<n; i++) sett.insert(arr2[i]);
        // arr2.clear();
        // for(auto &it : sett) arr2.emplace_back(it);
        
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());


        int ans = helper(0, 0, -1, arr1 ,arr2);
        
        if(ans > m) return -1;
        return ans;
    }

    int helper(int i, int j, int prev, vector<int>& arr1, vector<int>& arr2){
        if(i >= arr1.size()) return 0;

        j = upper_bound(arr2.begin()+j, arr2.end(), prev) - arr2.begin();

        if(dp[i][j] != -1) return dp[i][j];
        if(j >= arr2.size() && arr1[i] <= prev) return 2001;

        int take = 2001, not_take= 2001;
        //take
        if(j != arr2.size()) take = 1+helper(i+1, j+1, arr2[j], arr1, arr2);

        // not take
        if(arr1[i] > prev) not_take = helper(i+1, j, arr1[i],arr1, arr2);
        
        return dp[i][j] = min(take, not_take);
    }
};
