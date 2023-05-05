class Solution {
public:
    int maxVowels(string s, int k) {
        bool arr[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
        int ans=0;
        int curr=0;
        for(int i=0;i<s.size(); i++){
            curr += arr[s[i]-'a'];
            if(i>=k) curr -= arr[s[i-k]-'a'];
            ans = max(ans, curr);
        }
        return ans;
    }
};
