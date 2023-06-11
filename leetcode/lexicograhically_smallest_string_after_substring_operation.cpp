class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        
        int start = 0;
        while(start < s.size() && s[start] == 'a' ) start++;
        
        if(start == n) s[n-1] = 'z';
        else{
            int end = start;
            while(end< n && s[end] != 'a'){
                s[end] = s[end]-1;
                end++;
            }    
        }
        return s;
    }
};
