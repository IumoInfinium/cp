class Solution {
public:
    int strStr(string s, string p) {
        int m = p.size();
        if(!m) return 0;
        int n = s.size();
        int j=0;
        vector<int> pi(m,0);
        for(int i=1; i<m; i++){
            j = pi[i-1];
            while(j>0 && p[i]!=p[j]) j=pi[j-1];
            if(p[i] == p[j]) j++;
            pi[i] = j;
        }
        j=0;
        for(int i=0; i<n; i++){
            while(j>0 && p[j] != s[i]) j = pi[j-1];
            if(p[j] == s[i]) j++;
            if(j==m) return i-m+1;
        }
        return -1;
    }
};
