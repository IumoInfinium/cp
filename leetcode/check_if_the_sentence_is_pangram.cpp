class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> map(26,0);
        for(int i=0;i<s.size();i++){
            map[s[i]-'a']++;
        }
        for(int i : map){
            if(!(i>0)) return false;
        }
        return true;
    }
};
