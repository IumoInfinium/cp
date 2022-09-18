class Solution {
public:
    bool isAnagram(string s, string t) {
        int chrArr[26]={0};
        int pos;
        int f=1;
        for(int i=0;i<s.length();i++){
            pos=s[i]-'a';
            chrArr[pos]++;
        }
        for(int i=0;i<t.length();i++){
            pos=t[i]-'a';
            chrArr[pos]--;
        }
        for(int i=0;i<26;i++) if(chrArr[i]!=0) {f=0; break;}
        if(f) return true;
        return false;
        
    }
};
