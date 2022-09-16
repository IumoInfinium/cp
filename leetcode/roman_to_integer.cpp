class Solution {
public:
    int romanValue(char x){
        switch(x){
            case 'I': return 1; 
            case 'V': return 5; 
            case 'X': return 10;
            case 'L': return 50; 
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000; 
            default: return 0; 
        }
        return 0;
    }
    int romanToInt(string s) {
        int n=s.length();
        int ans=0,pre=1;
        for(int i=n-1;i>=0;--i){
            int curr=romanValue(s[i]);
            if(curr<pre)  ans-=curr;
            else pre=curr,ans+=curr;
        }
        return ans;
    
    }
};

