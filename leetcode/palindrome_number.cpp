class Solution {
public:
    bool isPalindrome(int x) {
        if(x>-1){
            int tmp=x;
            long long res=0;
            long long n=0,r;
            while(tmp!=0){
                tmp/=10;
                n+=1;
            }
            tmp=x;
            for(int i=n-1;i>=0;i--){
                r=tmp%10;
                res+=(pow(10,i)*r);
                tmp/=10;
            }
            if(res==x) return true;
            return false;
        }
        else return false;
    }
};