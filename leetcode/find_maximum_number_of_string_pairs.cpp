class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, bool> mp;
        int ans=0;
        string tmp;
        for(string& s :  words){
            tmp = s;
            reverse(begin(tmp), end(tmp));
            if(mp.count(tmp)) ans++;
            else mp[s]=true;
        }
        return ans;
	}
}	
