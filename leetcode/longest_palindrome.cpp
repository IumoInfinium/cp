class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int ans=0;
        for(char &c: s) mp[c]++;
        bool odd=false;
        for(auto &it: mp){
            if(it.second%2 && odd) ans+= (it.second-1);
            else if(it.second%2 == 0)ans+= it.second;
            else {ans+= (it.second);  odd=true;}
        }
        return ans;
    }
};
