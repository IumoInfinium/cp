class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1.length() < s2.length()) swap(s1,s2);

        int n=s1.length();
        int m=s2.length();
        // m < n
        
        int i=0;
        for(; i<m; i++)
            if(s1[i] != s2[i]) return "";
        
        if(n == m && i==m) return s2;
        return gcdOfStrings(s1.substr(i), s2);
    }
};
