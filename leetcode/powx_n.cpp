class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        bool f=n<0;
        while(n!=0){
            if(n&1){
                res*=x;
                n=f? n+1:n-1;
            }
            x*=x;
            n/=2;
        }
        return f?1/res : res;
    }
};
