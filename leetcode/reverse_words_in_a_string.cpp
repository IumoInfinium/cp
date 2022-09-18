class Solution {
public:
    void reverseword(string &s, int i,int j){
        while(i<j){
            char tmp=s[i];
            s[i++]=s[j];
            s[j--]=tmp;
        }
    }
    
    string reverseWords(string s) {
        int i=0,j=0,l=0;
        int n=s.length();
        int wordCount=0;
        while(true){
            while(i<n && s[i]==' ') i++;
            if(i==n) break;
            if(wordCount) s[j++]=' ';
            l=j;
            while(i<n && s[i]!=' '){
                s[j]=s[i];
                j++;i++;
            }
            reverseword(s,l,j-1);
            wordCount++;
        }
        s.resize(j);
        reverseword(s,0,j-1);
        return s;
    }
};
