class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=0;
        vector<int> lastPosition(256,-1);
        int i=0;
        for(int j=0;j<n;j++){
            i=max(i,lastPosition[s[j]]+1);
            ans=max(ans,j-i+1);
            lastPosition[s[j]]=j;
        }
        return ans;
    }
};