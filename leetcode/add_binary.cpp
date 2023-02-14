class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() > b.length()) return addBinary(b,a);

        while(b.length() != a.length()) a = '0'+a;
        int n = a.length();

        bool x,y,c=false;
        for(int i=n-1; i>=0; i--){
           x = a[i]-'0';
           y = b[i]-'0';
           a[i] = (x^y^c) ? '1' : '0';
           c = (x&y) | c&(x^y);
        }
        if(c) a='1'+a;
        return a;
    }
};
