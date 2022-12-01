class Solution {
public:
    bool charIs(char c){
        switch(c){
            case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': case 'E': case 'I': case 'O': case 'U': 
                return true;
                break;
            default: return false; break;
        }
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int c1=0,c2=0;
        int low=0, high=n-1;
        while(low<high){
            if(charIs(s[low])) c1++;
            if(charIs(s[high]))c2++;
            low++;
            high--;
        }

        if(c1 == c2) return true; 
        return false;
    }
};
