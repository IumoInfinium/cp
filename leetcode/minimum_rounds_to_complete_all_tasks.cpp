class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> freq;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            freq[tasks[i]]++;
        }
        int ans=0;
        for(auto& it : freq){
            if(it.second == 1) return -1;
            ans+= (it.second +2)/3;
        }
        return ans;
    }
};
