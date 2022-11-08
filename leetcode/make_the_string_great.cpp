class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        if(n==1) return s;
        string ans;
        for(char& c:s){
            if(!ans.empty() && (ans.back()^c) == 32) ans.pop_back();
            else ans.push_back(c);
        }
        return ans;
    }
};
