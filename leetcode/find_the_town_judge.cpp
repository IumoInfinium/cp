class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n,0);
        for(auto& e: trust){
            arr[e[0]-1]++;
            arr[e[1]-1]--;
        }
        for(int i=0;i<n;i++) if(arr[i]==-n+1) return i+1;
        return -1;
    }
};
