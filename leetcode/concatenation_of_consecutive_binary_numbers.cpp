class Solution {
public:
    
    // left shift the number and add it to get the concatenated number
    // a=1  ~~Binary = 1;
    // b=2  ~~Binary = 10;
    // on concatenating we get 110 (1+2) that's what we need !!
    // we can do this by leftShifting the 1, length(b) number of times
    // and add b to it to get the result
    // this takes log(n) time and since we do it for n numbers it becomes nlog(n);
    int concatenatedBinary(int n) {
        long ans=0, mod=1e9+7;
        for(int i=1;i <=n; i++){
            int len=0;
            
            for(int j=i; j ; j>>=1, ++len);
            ans = ((ans << len)%mod +i)%mod;
        }
        return ans;
    }
};
