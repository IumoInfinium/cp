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
    // bool halvesAreAlike(string s) {
    //     int n = s.size();
    //     int c1=0,c2=0;
    //     int low=0, high=n-1;
    //     while(low<high){
    //         if(charIs(s[low])) c1++;
    //         if(charIs(s[high]))c2++;
    //         low++;
    //         high--;
    //     }

    //     if(c1 == c2) return true; 
    //     return false;
    // }

    bool halvesAreAlike(string& s){
        int c1=0,c2=0;
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(charIs(s[i])) c1++;
            if(charIs(s[n-i-1])) c2++;
        }
        if(c1 != c2) return false;
        return true;
    }
};
