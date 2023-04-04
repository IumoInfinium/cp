class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,bool> mp;
        int n = s.size();
        int ans=1;
        for(int i=0; i<n; i++){
            if(mp.count(s[i])){
                mp.clear();
                mp[s[i]] = true;
                ans++;
            }
            else{
                mp[s[i]]= true;
            }
        }
        return ans;
    }
};
