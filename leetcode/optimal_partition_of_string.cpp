class Solution {
public:
    int partitionString(string s) {
        bool mp[26]={0};
        int n = s.size();
        int ans=1;
        for(int i=0; i<n; i++){
            if(mp[s[i]-'a']){
                memset(mp,false, sizeof(mp));
                mp[s[i]-'a'] = true;
                ans++;
            }
            else{
                mp[s[i]-'a']= true;
            }
        }
        return ans;
    }
};
