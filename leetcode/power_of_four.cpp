class Solution {
public:
    bool isPowerOfFour(int n) {
        // Method - 1
        // if(n>1)
        //     while(n%4==0) n/=4;
        // return n==1;
        
        //Method - 2
        // 1 - set bit in number's binary
        // 2- check if the set-bit is at odd position
        return n>0 && (n&(n-1))==0 && (n-1)%3==0;
    }
};
