class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
//         vector<pair<int,int>> flowers;
        
//         for(int i=0;i<plantTime.size();i++){
//             flowers.push_back({growTime[i],plantTime[i]});
//         }
//         sort(flowers.begin(),flowers.end());
//         int res=0;
//         for(auto& [g,p] : flowers){
//             res = max(res,g) + p;
//         }
//         return res;
        
        
        // METHOD 2 =================
//	method 1 is better
        int n = plantTime.size();
        vector<int> arr(100001,0);
        for(int i=0; i<n; i++){
            arr[growTime[i]] += plantTime[i];
        }
        int curr=0, ans=0;
        for(int i=arr.size()-1; i>=1; i--){
            if(arr[i] ==0) continue;
            curr += arr[i];
            ans=max(ans,curr+i);
        }
        return ans;
    }
};
