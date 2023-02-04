class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> map1(26,0);
        for(char& c: s1) map1[c-'a']++;

        int n = s1.length(), m = s2.length();

        for(int i=0; i< m-n+1; i++){
            vector<int> map2(26,0);
            for(int j=i; j<i+n; j++) map2[s2[j]-'a']++;
            
            if(map1 == map2) return true;
        }
        return false;
    }
};
